#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : _x(0), _y(0) {
	return;
}

Point::Point(const Point& src) : _x(src._x), _y(src._y) {
	return;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	return;
}

Point::~Point(void) {
	return;
}

Point& Point::operator=(const Point& rhs) {
	if (this != &rhs) {
		this->~Point();
		new (this) Point(rhs);
	}
	return *this;
}

bool Point::operator==(const Point& rhs) const {
    return _x == rhs._x && _y == rhs._y;
}


float Point::getX(void) const {
	return this->_x.toFloat();
}

float Point::getY(void) const {
	return this->_y.toFloat();
}

std::ostream & operator<<(std::ostream & os, const Point & rhs) {
	os << "Point(" << rhs.getX() << ", " << rhs.getY() << ")";
	return os;
}
