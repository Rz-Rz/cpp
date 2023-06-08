#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"
#include <cassert>
#include <sstream>

int main( void ) {
	/* Fixed a; */
	/* Fixed b( 10 ); */
	/* Fixed c( 42.42f ); */
	/* Fixed d( b ); */
	/* a = Fixed( 1234.4321f ); */
	/* std::cout << "a is " << a << std::endl; */
	/* std::cout << "b is " << b << std::endl; */
	/* std::cout << "c is " << c << std::endl; */
	/* std::cout << "d is " << d << std::endl; */
	/* std::cout << "a is " << a.toInt() << " as integer" << std::endl; */
	/* std::cout << "b is " << b.toInt() << " as integer" << std::endl; */
	/* std::cout << "c is " << c.toInt() << " as integer" << std::endl; */
	/* std::cout << "d is " << d.toInt() << " as integer" << std::endl; */

	/* a = 5; */
	/* b = 7; */
	/* // Comparison operators */
	/* std::cout << (a < b) << " this should be 1" << std::endl;   // Output: 1 (true) */
	/* std::cout << (a <= b) << " this should be 1"  << std::endl;  // Output: 1 (true) */
	/* std::cout << (a > b) << " this should be 0" << std::endl;   // Output: 0 (false) */
	/* std::cout << (a >= b) << " this should be 0" << std::endl;  // Output: 0 (false) */
	/* std::cout << (a == b) << " this should be 0" << std::endl;  // Output: 0 (false) */
	/* std::cout << (a != b) << " this should be 1"  << std::endl;  // Output: 1 (true) */

	/* c = a + b; */
	/* std::cout << c.toFloat() << " a + b should be 12" << std::endl;  // Output: 12 */

	/* d = a - b; */
	/* std::cout << d.toFloat() << " a - b should be -2" << std::endl;  // Output: -2 */

	/* Fixed e = a * b; */
	/* std::cout << e.toFloat() << " a * b should be 35" << std::endl;  // Output: 35 */

	/* Fixed f = a / b; */
	/* std::cout << f.toFloat() << " a / n should give 0" << std::endl;  // Output: 0 */

	/* // Increment/decrement operators */
	/* ++a; */
	/* std::cout << a.toFloat() <<  " a was incremented, should give a > 5" << std::endl; */

	/* Fixed g = b++; */
	/* std::cout << g.toFloat() << " post increment on b should give same number 7" << std::endl;  // Output: 7 */

	/* std::cout << b.toFloat() <<  " post increment in effect should give b>7 " << std::endl;  // Output: 8 */

	/* --b; */
	/* std::cout << b.toFloat() << " b was decremented, should give 7" << std::endl;  // Output: 7 */

	/* Fixed h = b--; */
	/* std::cout << h.toFloat() << " post decrement b should give same as before" << std::endl;  // Output: 7 */

	/* std::cout << b.toFloat() <<  "  post decrement b in effect should give b<7" << std::endl;  // Output: 6 */

	/* // max and min functions */
    /* Fixed maxVal = Fixed::max(a, b); */
    /* std::cout << maxVal << " max val between a and b" << std::endl; */

    /* Fixed minVal = Fixed::min(a, b); */
	/* std::cout << minVal << " min val between a and b" << std::endl; */

    // Test default constructor
    /* Point p1; */
    /* assert(p1.getX() == 0.0f); */
    /* assert(p1.getY() == 0.0f); */

    /* // Test constructor with parameters */
    /* Point p2(1.0f, 2.0f); */
    /* assert(p2.getX() == 1.0f); */
    /* assert(p2.getY() == 2.0f); */

    /* // Test copy constructor */
    /* Point p3(p2); */
	/* std::cout << "p3" << p3 << std::endl; */
	/* std::cout << "p2" << p2 << std::endl; */
    /* assert(p3.getX() == p2.getX()); */
    /* assert(p3.getY() == p2.getY()); */

    /* // Test assignment operator */
    /* p1 = p2; */
	/* std::cout << "p1 has been assigned p2" << p1 << std::endl; */
	/* std::cout <<  "p2" << p2 << std::endl; */
    /* assert(p1.getX() == p2.getX()); */
    /* assert(p1.getY() == p2.getY()); */

    /* // Test output operator */
    /* std::ostringstream os; */
    /* os << p1; */
    /* assert(os.str() == "Point(1, 2)"); */

	 // Test 1: Point is inside the triangle
    Point a1(0, 0), b1(5, 0), c1(2, 5), p1(2, 2);
    assert(bsp(a1, b1, c1, p1) == true);
	std::cout << "Test 1 passed" << std::endl;

    // Test 2: Point is outside the triangle
    Point a2(0, 0), b2(5, 0), c2(2, 5), p2(6, 6);
    assert(bsp(a2, b2, c2, p2) == false);
	std::cout << "Test 2 passed" << std::endl;

    // Test 3: Point is on the vertex of the triangle
    Point a3(0, 0), b3(5, 0), c3(2, 5), p3(0, 0);
    assert(bsp(a3, b3, c3, p3) == false);
	std::cout << "Test 3 passed" << std::endl;

    // Test 4: Point is on the edge of the triangle
    Point a4(0, 0), b4(5, 0), c4(2, 5), p4(2.5, 0);
    assert(bsp(a4, b4, c4, p4) == false);
	std::cout << "Test 4 passed" << std::endl;

	return 0;
}
