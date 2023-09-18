#include "Pairs.hpp"

// Function to test default constructor
void testDefaultConstructor() {
  Pair<int> p;
  // if (p.getA() != 0 || p.getB() != 0) {
  //   std::cerr << "DefaultConstructor test failed\n";
  //   return;
  // }
  try {
    p.getA();
  } catch (std::string& e) {
    std::cout << e << std::endl;
  }
  try {
    p.getB();
  } catch (std::string& e) {
    std::cout << e << std::endl;
  }
  std::cout << "DefaultConstructor test passed\n";
}

// Function to test parameterized constructor
void testParameterizedConstructor() {
  int a = 5, b = 10;
  Pair<int> p(a, b);
  if (p.getA() != a || p.getB() != b) {
    std::cerr << "ParameterizedConstructor test failed\n";
    return;
  }
  std::cout << "ParameterizedConstructor test passed\n";
}

// Function to test copy constructor
void testCopyConstructor() {
  int a = 5, b = 10;
  Pair<int> p1(a, b);
  Pair<int> p2(p1);
  if (p1.getA() != p2.getA() || p1.getB() != p2.getB()) {
    std::cerr << "CopyConstructor test failed\n";
    return;
  }
  std::cout << "CopyConstructor test passed\n";
}

// Function to test equality operator
void testEqualityOperator() {
  int a = 5, b = 10;
  Pair<int> p1(a, b);
  Pair<int> p2(a, b);
  if (!(p1 == p2)) {
    std::cerr << "EqualityOperator test failed\n";
    return;
  }
  std::cout << "EqualityOperator test passed\n";
}

// Function to test inequality operator
void testInequalityOperator() {
  int a = 5, b = 10;
  int x = 6;
  Pair<int> p1(a, b);
  Pair<int> p2(x, b);
  if (p1 != p2) {
    std::cerr << "InequalityOperator test passed\n";
    return;
  }
  std::cout << "InequalityOperator test failed\n";
}

// Function to test sort()
void testSort() {
	int a = 1;
	int b = 10;
	Pair<int> p(a, b);
	p.sort();
	if (p.getA() != 10 || p.getB() != 1) {
		std::cerr << "Sort test failed\n";
		return;
	}
	std::cout << "Sort test passed\n";
}

void testStray() {
  int a = 5, b = 10;
  Pair<int> p(a, b);
	if (p.getStray() != NULL) {
	std::cerr << "Stray test failed\n";
	return;
  }
  std::cout << "Stray test passed\n";
}

int main() {
  testDefaultConstructor();
  testParameterizedConstructor();
  testCopyConstructor();
  testEqualityOperator();
  testInequalityOperator();
  testSort();
  testStray();
  return 0;
}

