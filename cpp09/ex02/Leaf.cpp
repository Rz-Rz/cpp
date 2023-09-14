#include "Leaf.hpp"
#include "SmartPointer.hpp"

Leaf::Leaf() : _value(0), _processed(false) {}

Leaf::Leaf(long double value) : _value(value), _processed(false) {}

Leaf::Leaf(const Leaf &l) : BasePair(l), _value(l._value), _processed(l._processed) {}

Leaf::~Leaf() {}

void Leaf::print() const {
	std::cout << _value;
}

BasePair* Leaf::getLeafA() {
    return this;
}

BasePair* Leaf::getLeafB() {
    return this;  // Same reasoning here
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

void Leaf::s_was_processed() {
  _processed = true;
}

bool Leaf::a_processed_state() const {
  return _processed;
}

bool Leaf::b_processed_state() const {
  return _processed;
}

bool Leaf::s_processed_state() const {
  return _processed;
}

bool Leaf::is_stray() const {
  return false;
}
