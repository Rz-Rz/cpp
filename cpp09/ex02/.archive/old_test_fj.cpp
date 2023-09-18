#include "AbstractPairs.hpp"
#include "Leaf.hpp"
#include <vector>
#include "Stack.hpp"
#include "BinarySearch.hpp"

std::vector<SmartPointer<BasePair> > longDoubleToPairVector(std::vector<long double> &unsorted_list)
{
  std::vector<SmartPointer<BasePair> > pairVector(unsorted_list.size());
  for (unsigned long i = 0; i < unsorted_list.size(); i++)
  {
    pairVector[i] = SmartPointer<BasePair>(new Leaf(unsorted_list[i]));
  }
  return pairVector;
}

void ford_johnson(std::vector<long double> &unsorted_list)
{
  Stack<std::vector<SmartPointer<BasePair> > > stack;
  SmartPointer<BasePair> stray;
  int stop = unsorted_list.size();
  std::vector<SmartPointer<BasePair> > pairVector = longDoubleToPairVector(unsorted_list);

  //create a while loop that will run until the list is sorted
  while (stop >= 2)
  {
    // Create a new vector that will hold pairs
    std::vector<SmartPointer<BasePair> > newVector(pairVector.size() / 2);
    //save the last element if the list is odd
    // if (pairVector.size() % 2 == 1)
    // {
    //   std::cout << "stray" << std::endl;
    //   stray = pairVector.back();
    // }
    SmartPointer<BasePair> newPair;
    for (unsigned long i = 0; i < pairVector.size() / 2; i++)
    {
      if (i + 1 == pairVector.size() / 2 && pairVector.size() % 2 == 1)
      {
        stray = pairVector.back();
        newPair = SmartPointer<BasePair>(new Pair(pairVector[i * 2].operator->(), pairVector[i * 2 + 1].operator->(), stray.operator->()));
        pairVector.pop_back();
      }
      else
        newPair = SmartPointer<BasePair>(new Pair(pairVector[i * 2].operator->(), pairVector[i * 2 + 1].operator->()));
      //Add the new pair to the new vector
      newVector[i] = newPair;
    }
    pairVector = newVector;
    stop /= 2;
		//The vector is full of pairs, we can simulate the behaviour of a recursive call by pushing it in a stack.
    stack.push(newVector);
  }
  Stack<std::vector<SmartPointer<BasePair> > > check = stack;
  check.print();

  insertPairs(stack);
}

void printMain(std::vector<long double> mainChain)
{
  std::cout << "main chain is " << std::endl;
  for (unsigned long i = 0; i < mainChain.size(); i++)
  {
    std::cout << mainChain[i] << " ";
  }
  std::cout << std::endl;
}

// jacobstahl_n = jacobstahl_n_1 + 2 * jacobstahl_n_2
static int jacobstahl_n(int jacobstahl_n_1, int jacobstahl_n_2)
{
  return (jacobstahl_n_1 + 2 * jacobstahl_n_2);
}

std::vector<long double> insertPairs(Stack<std::vector<SmartPointer<BasePair> > > &stack)
{
  int J_upper = 1;
  int J_lower = 1;
  int tmp = J_lower;
  std::vector<long double>::iterator last;
  std::vector<long double>::iterator pos;
  std::vector<long double> mainChain;

  //work with the different list of pairs in the stack
  while (!stack.isEmpty())
  {
    std::vector<SmartPointer<BasePair> > pairVector = stack.top();
    stack.pop();
    // mainChain 
    mainChain.push_back(pairVector[0].get()->b());
    mainChain.push_back(pairVector[0].get()->a());
    if (J_upper == static_cast<int>(pairVector.size()) && pairVector.back().get()->is_stray())
    {
      pos = binarySearch(mainChain.begin(), mainChain.end(), pairVector.back().get()->s());
      mainChain.insert(pos, pairVector.back().get()->s()); 
    }
    printMain(mainChain);
    // std::cout << "pairVector size is " << pairVector.size() << std::endl;
    while (J_upper < static_cast<int>(pairVector.size()))
    {
      //set jacobstahl values
      tmp = J_lower;
      J_lower = J_upper;
      J_upper = std::min(jacobstahl_n(J_lower, tmp), static_cast<int>(pairVector.size()));
      // std::cout << "J_upper is " << J_upper << std::endl;
      // std::cout << "J_lower is " << J_lower << std::endl;
      // std::cout << "tmp is " << tmp << std::endl;  

      // Insert all A's into the mainchain
      for (int i = J_lower; i < J_upper; i++)
        mainChain.push_back(pairVector[i].get()->a());
      //first insert stray if it exists
      // std::cout << "checking stray again. PairVector size is " << pairVector.size() << std::endl;
      if (pairVector.back().get()->is_stray() && J_upper == static_cast<int>(pairVector.size()))
      {
        pos = binarySearch(mainChain.begin(), mainChain.end(), pairVector[J_upper].get()->s());
        mainChain.insert(pos, pairVector.back().get()->s());
      }
      // Insert all B's into the mainChain
      for (int i = J_upper - 1; i >= J_lower; i--)
      {
        if (J_upper == static_cast<int>(pairVector.size()))
          last = mainChain.end();
        else
          last = mainChain.begin() + J_upper + J_lower - 1;
        pos = binarySearch(mainChain.begin(), last, pairVector[i].get()->b());
        mainChain.insert(pos, pairVector[i].get()->b());
      }
      // std::cout << "main chain after inserting all b's is " << std::endl;
      // printMain(mainChain);
      std::cout << "main chain is " << std::endl;
      printMain(mainChain);
    }
  }
  printMain(mainChain);
  return mainChain;
}

int main()
{
  long double arr[] = {7, 8, 5, 9, 11, 0, 2, 1, 10, 3, 4, 6};
  std::vector<long double> v;
  v.insert(v.end(), arr, arr + sizeof(arr)/sizeof(arr[0]));
	ford_johnson(v);
	return 0;
}
