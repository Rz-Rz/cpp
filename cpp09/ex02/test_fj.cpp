#include "AbstractPairs.hpp"
#include "Leaf.hpp"
#include <vector>
#include "Stack.hpp"
#include "BinarySearch.hpp"

std::vector<BasePair*> longDoubleToPairVector(std::vector<long double> &unsorted_list)
{
  std::vector<BasePair*> pairVector(unsorted_list.size());
  for (unsigned long i = 0; i < unsorted_list.size(); i++)
  {
    pairVector[i] = new Leaf(unsorted_list[i]);
  }
  return pairVector;
}

void ford_johnson(std::vector<long double> &unsorted_list)
{
  Stack<std::vector<BasePair*>> stack;
  BasePair* stray = nullptr;
  int stop = unsorted_list.size();
  std::vector<BasePair*> pairVector = longDoubleToPairVector(unsorted_list);

  //create a while loop that will run until the list is sorted
  while (stop >= 2)
  {
    // Create a new vector that will hold pairs
    std::vector<BasePair*> newVector(pairVector.size() / 2);

    BasePair* newPair = nullptr;
    for (unsigned long i = 0; i < pairVector.size() / 2; i++)
    {
      if (i + 1 == pairVector.size() / 2 && pairVector.size() % 2 == 1)
      {
        stray = pairVector.back();
        newPair = new Pair(pairVector[i * 2], pairVector[i * 2 + 1], stray);
        pairVector.pop_back();
      }
      else
        newPair = new Pair(pairVector[i * 2], pairVector[i * 2 + 1]);

      //Add the new pair to the new vector
      newVector[i] = newPair;
    }
    pairVector = newVector;
    stop /= 2;
    //The vector is full of pairs, we can simulate the behaviour of a recursive call by pushing it in a stack.
    stack.push(newVector);
  }

  Stack<std::vector<BasePair*>> check = stack;
  check.print();

  // insertPairs(stack);
}

// Remember to clean up memory when you're done!
void cleanUp(std::vector<BasePair*>& vec) {
  for(BasePair* ptr : vec) {
    delete ptr;
  }
}

