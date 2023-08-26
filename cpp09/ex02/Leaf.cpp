#include "Leaf.hpp"
#include "SmartPointer.hpp"

Leaf::Leaf() : _value(0) {}

Leaf::Leaf(long double value) : _value(value) {}

Leaf::Leaf(const Leaf &l) : BasePair(l), _value(l._value) {}

Leaf::~Leaf() {}

void Leaf::print() const {
	std::cout << _value;
}

SmartPointer<BasePair> Leaf::clone() const {
	return SmartPointer<BasePair>(new Leaf(*this));
}

long double Leaf::b() const {
	return _value;
}

long double Leaf::a() const {
	return _value;
}

long double Leaf::s() const {
  return _value;
}

long double Leaf::stray() const {
	return _value;
}

void Leaf::setValue(long double value) {
	_value = value;
}

bool Leaf::is_stray() const {
  return false;
}
