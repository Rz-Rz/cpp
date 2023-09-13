#include "AbstractPairs.hpp"
#include "Leaf.hpp"
#include <vector>
#include "Stack.hpp"
#include "BinarySearch.hpp"

std::vector<long double> insertPairs(Stack<std::vector<BasePair*> > &stack);

void printMain(std::vector<long double> mainChain)
{
  std::cout << "main chain is " << std::endl;
  for (unsigned long i = 0; i < mainChain.size(); i++)
  {
    std::cout << mainChain[i] << " ";
  }
  std::cout << std::endl;
}

static int jacobstahl_n(int jacobstahl_n_1, int jacobstahl_n_2)
{
  return (jacobstahl_n_1 + 2 * jacobstahl_n_2);
}

std::vector<BasePair*> longDoubleToPairVector(std::vector<long double> &unsorted_list)
{
  std::vector<BasePair*> pairVector(unsorted_list.size());
  for (unsigned long i = 0; i < unsorted_list.size(); i++)
  {
    pairVector[i] = new Leaf(unsorted_list[i]);
  }
  return pairVector;
}

void cleanUp(std::vector<BasePair*>& vec) {
    for(std::vector<BasePair*>::iterator it = vec.begin(); it != vec.end(); ++it) {
        delete *it;
    }
    vec.clear();
}

void ford_johnson(std::vector<long double> &unsorted_list)
{
  Stack<std::vector<BasePair*> > stack;
  BasePair* stray = NULL;
  int stop = unsorted_list.size();
  std::vector<BasePair*> pairVector = longDoubleToPairVector(unsorted_list);

  //create a while loop that will run until the list is sorted
  while (stop >= 2)
  {
    // Create a new vector that will hold pairs
    std::vector<BasePair*> newVector(pairVector.size() / 2);

    BasePair* newPair = NULL;
    for (unsigned long i = 0; i < pairVector.size() / 2; i++)
    {
      if (i + 1 == pairVector.size() / 2 && pairVector.size() % 2 == 1)
      {
        stray = pairVector.back();
        newPair = new Pair(*pairVector[i * 2], *pairVector[i * 2 + 1], *stray);
        pairVector.pop_back();
      }
      else
        newPair = new Pair(*pairVector[i * 2], *pairVector[i * 2 + 1]);

      //Add the new pair to the new vector
      newVector[i] = newPair;
    }
    pairVector = newVector;
    stop /= 2;
    //The vector is full of pairs, we can simulate the behaviour of a recursive call by pushing it in a stack.
    stack.push(newVector);
  }
  // Stack<std::vector<BasePair*> > check = stack;
  // check.print();

  insertPairs(stack);
}

std::vector<long double> insertPairs(Stack<std::vector<BasePair*> > &stack)
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
    std::vector<BasePair*> pairVector = stack.top();
    stack.pop();
    // mainChain 
    mainChain.push_back(pairVector[0]->b());
    mainChain.push_back(pairVector[0]->a());
    if (J_upper == static_cast<int>(pairVector.size()) && pairVector.back()->is_stray())
    {
      pos = binarySearch(mainChain.begin(), mainChain.end(), pairVector.back()->s());
      mainChain.insert(pos, pairVector.back()->s()); 
    }
    printMain(mainChain);
    std::cout << "pairVector size is " << pairVector.size() << std::endl;
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
        mainChain.push_back(pairVector[i]->a());
      //first insert stray if it exists
      // std::cout << "checking stray again. PairVector size is " << pairVector.size() << std::endl;
      if (pairVector.back()->is_stray() && J_upper == static_cast<int>(pairVector.size()))
      {
        pos = binarySearch(mainChain.begin(), mainChain.end(), pairVector[J_upper]->s());
        mainChain.insert(pos, pairVector.back()->s());
      }
      // Insert all B's into the mainChain
      for (int i = J_upper - 1; i >= J_lower; i--)
      {
        if (J_upper == static_cast<int>(pairVector.size()))
          last = mainChain.end();
        else
          last = mainChain.begin() + J_upper + J_lower - 1;
        pos = binarySearch(mainChain.begin(), last, pairVector[i]->b());
        mainChain.insert(pos, pairVector[i]->b());
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
