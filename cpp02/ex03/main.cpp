#include <iostream>
#include "Fixed.hpp"

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

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
