#include "AbstractPairs.hpp"
#include "Leaf.hpp"
#include <cassert>

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

void testPairPrinting(){

}


int main()
{
	testPairParameterizedConstructor();
	testPairCopyConstructor();
	testPairComparisonOperators();
	// testPairSort();
	return 0;
}

