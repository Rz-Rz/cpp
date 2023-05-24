#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream& os, const Fixed& rhs) {
	os << rhs.toFloat();
	return os;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(float const value) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

int Fixed::getRawBits(void) const {
	/* std::cout << "getRawBits member function called" << std::endl; */
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	/* std::cout << "setRawBits member function called" << std::endl; */
	this->_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const {
	return this->_fixedPointValue >> _fractionalBits;
}

bool Fixed::operator==(const Fixed& rhs) const {
	return this->_fixedPointValue == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return this->_fixedPointValue != rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const {
	return this->_fixedPointValue < rhs.getRawBits();
}

bool Fixed::operator>(const Fixed& rhs) const {
	return this->_fixedPointValue > rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return this->_fixedPointValue <= rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return this->_fixedPointValue >= rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++() {
	++this->_fixedPointValue;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed& Fixed::operator--() {
	--this->_fixedPointValue;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}







