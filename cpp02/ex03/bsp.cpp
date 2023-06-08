#include "Fixed.hpp"
#include "Point.hpp"
#include "cmath"

void swapPoints(Point& a, Point& b) {
    Point temp = a;
    a = b;
    b = temp;
}

Point createVector2P(Point p1, Point p2) {
	Point result(p1.getX() - p2.getX(), p1.getY() - p2.getY());
	return result;
}

Point leftNormal(Point p1, Point p2) {
	Point result(-1 * (p2.getY() - p1.getY()), p2.getX() - p1.getX());
	return result;
}

double dotProduct(Point v1, Point v2) {
	return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	Point center((a.getX() + b.getX() + c.getX()) / 3, (a.getY() + b.getY() + c.getY()) / 3);

	Point a_san = a, b_san = b, c_san = c;

	 // Compute angles relative to the center point
    double angleA = std::atan2(a.getY() - center.getY(), a.getX() - center.getX());
    double angleB = std::atan2(b.getY() - center.getY(), b.getX() - center.getX());
    double angleC = std::atan2(c.getY() - center.getY(), c.getX() - center.getX());

 // Sort points by angle to ensure counterclockwise order
	if (angleA > angleB) {
		if (angleB > angleC) { // BAC
			swapPoints(a_san, b_san);
		} else if (angleA > angleC) { // BCA
			swapPoints(a_san, c_san);
		} else { // CAB
			swapPoints(a_san, b_san);
			swapPoints(b_san, c_san);
		}
	} else if (angleA > angleC) { // CBA
		swapPoints(b_san, c_san);
	} else if (angleB > angleC) { // ACB
		swapPoints(a_san, b_san);
		swapPoints(a_san, c_san);
	} // else ABC

	// Compute vectors corresponding to sides of triangle
	Point v1 = createVector2P(b_san, a_san);
	Point v2 = createVector2P(c_san, b_san);
	Point v3 = createVector2P(a_san, c_san);

	// Compute normals to sides of triangle
	Point n1 = leftNormal(a_san, b_san);
	Point n2 = leftNormal(b_san, c_san);
	Point n3 = leftNormal(c_san, a_san);

	// Compute vectors from vertices to point
    Point v1p = createVector2P(point, a);
    Point v2p = createVector2P(point, b);
    Point v3p = createVector2P(point, c);

	return (dotProduct(n1, v1p) > 0 && dotProduct(n2, v2p) > 0 && dotProduct(n3, v3p) > 0);
}
