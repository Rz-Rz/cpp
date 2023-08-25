#include "AbstractPairs.hpp"
#include "Leaf.hpp"
#include <vector>
#include "Stack.hpp"

#include <cassert>
// #include "PmergeMe.hpp"

void testPairParameterizedConstructor() {
  Leaf leafA(10.0);
  Leaf leafB(20.0);
  Pair pair(&leafA, &leafB);
  // std::cout << "a is " << pair.a() << std::endl; 
  // std::cout << "b is " << pair.b() << std::endl; 
  assert(pair.a() == 20.0);
  assert(pair.b() == 10.0);
}

void testPairCopyConstructor() {
  Leaf leafA(10.0);
  Leaf leafB(20.0);
  Pair original(&leafA, &leafB);
  Pair copy(original);
  // std::cout << "a is " << copy.a() << std::endl; 
  // std::cout << "b is " << copy.b() << std::endl; 
  assert(copy.a() == 20.0);
  assert(copy.b() == 10.0);
}
//
void testPairComparisonOperators() {
  Leaf leafA(10.0);
  Leaf leafB(20.0);
  Leaf leafC(30.0);
  Leaf leafD(30.0);
  Pair pair1(&leafA, &leafB);
  Pair pair2(&leafA, &leafB);
	Pair pair3(&leafB, &leafC);
  Pair pair4(&leafC, &leafA);

	if (pair1 == pair2) {
		std::cout << "pair1 == pair2 is true, test passed" << std::endl;
	}
	else {
		std::cout << "pair1 == pair2 is false, test failed" << std::endl;
	}

  if (pair1 != pair2)
  {
    std::cout << "pair1 != pair2 is false, test failed" << std::endl;
  }
  else
  {
    std::cout << "pair1 != pair2 is true, test passed" << std::endl;
  }

	if (pair1 != pair3) {
		std::cout << "pair1 != pair3 is true, test passed" << std::endl;
	}

	else {
		std::cout << "pair1 != pair3 is false, test failed" << std::endl;
	}

  if (pair1 == pair3)
  {
    std::cout << "pair1 == pair3 is false, test failed" << std::endl;
  }
  else
  {
    std::cout << "pair1 == pair3 is false, test passed" << std::endl;
  }

	if (!(pair1 != pair2)) {
		std::cout << "!(pair1 != pair2) is true, test passed" << std::endl;
	}
	else {
		std::cout << "!(pair1 != pair2) is false, test failed" << std::endl;
	}

  if (pair3 > pair1)
  {
    std::cout << "pair3 > pair1 is true, test passed" << std::endl;
  }
  else
  {
    std::cout << "pair3 > pair1 is false, test failed" << std::endl;
  }

  if (pair1 > pair3)
  {
    std::cout << "pair1 > pair3 is false, test failed" << std::endl;
  }
  else
  {
    std::cout << "pair1 > pair3 is false, test passed" << std::endl;
  }

  if (pair1 < pair3)
  {
    std::cout << "pair1 < pair3 is true, test passed" << std::endl;
  }
  else
  {
    std::cout << "pair1 < pair3 is false, test failed" << std::endl;
  }

  if (pair3 < pair1)
  {
    std::cout << "pair3 < pair1 is false, test failed" << std::endl;
  }
  else
  {
    std::cout << "pair3 < pair1 is false, test passed" << std::endl;
  }

  if (pair3 >= pair1)
  {
    std::cout << "pair3 >= pair1 is true, test passed" << std::endl;
  }
  else
  {
    std::cout << "pair3 >= pair1 is false, test failed" << std::endl;
  }

  if (pair1 >= pair3)
  {
    std::cout << "pair1 >= pair3 is false, test failed" << std::endl;
  }
  else
  {
    std::cout << "pair1 >= pair3 is false, test passed" << std::endl;
  }

  if (pair1 <= pair3)
  {
    std::cout << "pair1 <= pair3 is true, test passed" << std::endl;
  }
  else
  {
    std::cout << "pair1 <= pair3 is false, test failed" << std::endl;
  }

  if (pair3 <= pair1)
  {
    std::cout << "pair3 <= pair1 is false, test failed" << std::endl;
  }
  else
  {
    std::cout << "pair3 <= pair1 is false, test passed" << std::endl;
  }

  if (pair3 >= pair4)
  {
    std::cout << "pair3 >= pair4 is true, test passed" << std::endl;
  }
  else
  {
    std::cout << "pair3 >= pair4 is false, test failed" << std::endl;
  }

  if (pair3 <= pair4)
  {
    std::cout << "pair3 <= pair4 is true, test passed" << std::endl;
  }
  else
  {
    std::cout << "pair3 <= pair4 is false, test failed" << std::endl;
  }
}

//test the print method
void testPairPrinting() {
  Leaf leafA(10.0);
  Leaf leafB(20.0);
  Leaf leafC(30.0);
  Leaf leafD(40.0);
  Pair pair(&leafA, &leafB);
  Pair pair2(&leafC, &leafD);
  Pair pair3(&pair, &pair2);
  // std::cout << "pair is " << pair << std::endl;
  // pair.print();
  // pair2.print();
  pair3.print();
}

//long double to base pair vector
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
        std::cout << "stray 2" << std::endl;
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
  stack.print();
}

int main()
{
	// testPairParameterizedConstructor();
	// testPairCopyConstructor();
	// testPairComparisonOperators();
  // testPairPrinting();

	std::vector<long double> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	ford_johnson(v);
	return 0;
}
