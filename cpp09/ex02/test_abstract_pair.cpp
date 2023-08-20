#include "AbstractPairs.hpp"
#include "Leaf.hpp"
#include <cassert>

void testPairParameterizedConstructor() {
  Leaf leafA(10.0);
  Leaf leafB(20.0);
  Pair pair(&leafA, &leafB);
  assert(pair.a() == 10.0);
  assert(pair.b() == 20.0);
}

// void testPairCopyConstructor() {
//   Leaf leafA(10.0);
//   Leaf leafB(20.0);
//   Pair original(&leafA, &leafB);
//   Pair copy(original);
//   assert(copy.a() == 10.0);
//   assert(copy.b() == 20.0);
// }
//
// void testPairComparisonOperators() {
//     Leaf leafA(10.0);
//     Leaf leafB(20.0);
//     Pair pair1(&leafA, &leafB);
//     Pair pair2(&leafA, &leafB);
// 	Pair pair3(&leafB, &leafA);
// 	if (pair1 == pair2) {
// 		std::cout << "pair1 == pair2 is true, test passed" << std::endl;
// 	}
// 	else {
// 		std::cout << "pair1 == pair2 is false, test failed" << std::endl;
// 	}
// 	if (pair1 != pair3) {
// 		std::cout << "pair1 != pair3 is true, test passed" << std::endl;
// 	}
// 	else {
// 		std::cout << "pair1 != pair3 is false, test failed" << std::endl;
// 	}
// 	if (!(pair1 != pair2)) {
// 		std::cout << "!(pair1 != pair2) is true, test passed" << std::endl;
// 	}
// 	else {
// 		std::cout << "!(pair1 != pair2) is false, test failed" << std::endl;
// 	}
// }
//
// void testPairSort() {
//     Leaf leafA(20.0);
//     Leaf leafB(10.0);
//     Pair pair(&leafA, &leafB);
//     pair.sort();
// 	assert(pair.a() == 10.0);
// 	assert(pair.b() == 20.0);
// }

int main()
{
	testPairParameterizedConstructor();
	// testPairCopyConstructor();
	// testPairComparisonOperators();
	// testPairSort();
	return 0;
}

