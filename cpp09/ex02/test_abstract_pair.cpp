#include "AbstractPairs.hpp"
#include "Leaf.hpp"
#include <vector>
#include "Stack.hpp"
#include "BinarySearch.hpp"

#include <cassert>
// #include "PmergeMe.hpp"

 void testPairParameterizedConstructor() {
   // Leaf leafA(10.0);
   // Leaf leafB(20.0);
   BasePair* leafA = new Leaf(10.0);
    BasePair* leafB = new Leaf(20.0);
   Pair pair(*leafA, *leafB);
   // std::cout << "a is " << pair.a() << std::endl; 
   // std::cout << "b is " << pair.b() << std::endl; 
   assert(pair.a() == 20.0);
   assert(pair.b() == 10.0);
 }
 //
 void testPairCopyConstructor() {
   // Leaf leafA(10.0);
   // Leaf leafB(20.0);

   BasePair* leafA = new Leaf(10.0);
   BasePair* leafB = new Leaf(20.0);
   Pair original(*leafA, *leafB);
   Pair copy(original);
   // std::cout << "a is " << copy.a() << std::endl; 
   // std::cout << "b is " << copy.b() << std::endl; 
   assert(copy.a() == 20.0);
   assert(copy.b() == 10.0);
 }

 void testPairComparisonOperators() {
   // Leaf leafA(10.0);
   // Leaf leafB(20.0);
   // Leaf leafC(30.0);
   // Leaf leafD(30.0);
   BasePair* leafA = new Leaf(10.0);
   BasePair* leafB = new Leaf(20.0);
   BasePair* leafC = new Leaf(30.0);
   // BasePair* leafD = new Leaf(30.0);
   Pair pair1(*leafA, *leafB);
   Pair pair2(*leafA, *leafB);
   Pair pair3(*leafB, *leafC);
   Pair pair4(*leafC, *leafA);

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

void testLeafProcessedState() {

  BasePair* leafA = new Leaf(10.0);
  BasePair* leafB = new Leaf(20.0);
  BasePair* leafC = new Leaf(30.0);
  BasePair* leafD = new Leaf(40.0);

  Pair pair(*leafA, *leafB);
  Pair pair2(*leafC, *leafD);
  Pair pair3(pair, pair2);

    // Initial state: none of the leaves should be processed.
    assert(!pair.a_processed_state());
    assert(!pair.b_processed_state());

    // Marking a as processed
    pair.a_was_processed();
    assert(pair.a_processed_state());  // a should be processed now
    assert(!pair.b_processed_state()); // b should still be unprocessed

    // Marking b as processed
    pair.b_was_processed();
    assert(pair.a_processed_state());  // a should be processed
    assert(pair.b_processed_state());  // b should be processed now
                                       //
    std::cout << "leafA was processed: " << leafA->a_processed_state() << std::endl;
    std::cout << "leafB was processed: " << leafB->a_processed_state() << std::endl;
    std::cout << "Pair3 a() was not processed: " << pair3.a_processed_state() << std::endl;
    std::cout << "Pair3 b() was processed: " << pair3.b_processed_state() << std::endl;
}


//test the print method
void testPairPrinting() {
  BasePair* leafA = new Leaf(10.0);
  BasePair* leafB = new Leaf(20.0);
  BasePair* leafC = new Leaf(30.0);
  BasePair* leafD = new Leaf(40.0);
  BasePair* leafX = new Leaf(30.0);
  BasePair* leafZ = new Leaf(40.0);

  Pair pair(*leafA, *leafB);
  Pair pair2(*leafC, *leafD);
  Pair pair3(*leafX, *leafZ);
  Pair pairx(*leafA, *leafZ);

  Pair pair4(pair, pair2);
  Pair pair5(pair3, pairx);
  Pair pair6(pair4, pair5);
  std::cout << "pair is " << pair << std::endl;
  pair.print();
  pair2.print();
  pair3.print();
}

int main()
{
	// testPairParameterizedConstructor();
	testPairCopyConstructor();
	testPairComparisonOperators();
  testPairPrinting();
  testLeafProcessedState();

	// std::vector<long double> v = {7, 8, 5, 9, 11, 0, 2, 1, 10, 3, 4, 6};
  // long double arr[] = {7, 8, 5, 9, 11, 0, 2, 1, 10, 3, 4, 6};
  // std::vector<long double> v;
  // v.insert(v.end(), arr, arr + sizeof(arr)/sizeof(arr[0]));
	// for (int i = 0; i < 10; i++)
	// 	v.push_back(i);
	// ford_johnson(v);
	return 0;
}
