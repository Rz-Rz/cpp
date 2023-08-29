#include "Leaf.hpp"
#include "SmartPointer.hpp"

Leaf::Leaf() : _value(0), _processed(false) {}

Leaf::Leaf(long double value) : _value(value), _processed(false) {}

Leaf::Leaf(const Leaf &l) : BasePair(l), _value(l._value), _processed(l._processed) {}

Leaf::~Leaf() {}

void Leaf::print() const {
	std::cout << _value;
}

SmartPointer<BasePair> Leaf::getLeafA() const {
    return SmartPointer<BasePair>(const_cast<Leaf*>(this));  // Using const_cast because 'this' is const in a const member function
}

SmartPointer<BasePair> Leaf::getLeafB() const {
    return SmartPointer<BasePair>(const_cast<Leaf*>(this));  // Same reasoning here
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

void Leaf::a_was_processed() {
  _processed = true;
}

void Leaf::b_was_processed() {
  _processed = true;
}

bool Leaf::a_processed_state() const {
  return _processed;
}

bool Leaf::b_processed_state() const {
  return _processed;
}

bool Leaf::is_stray() const {
  return false;
}
