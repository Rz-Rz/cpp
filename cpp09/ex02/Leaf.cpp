#include "Leaf.hpp"

Leaf::Leaf() : _value(0) {}

Leaf::Leaf(long double value) : _value(value) {}

Leaf::Leaf(const Leaf &l) : _value(l._value) {}

Leaf::~Leaf() {}

void Leaf::print() const {
	std::cout << _value;
}

BasePair *Leaf::clone() const {
	return new Leaf(*this);
}

long double Leaf::getValue() const {
	return _value;
}

void Leaf::setValue(long double value) {
	_value = value;
}
