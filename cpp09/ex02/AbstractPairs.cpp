#include "AbstractPairs.hpp"

Pair::Pair() : _a(NULL), _b(NULL), _stray(NULL) {};

Pair::Pair(BasePair *a, BasePair *b) : _a(a->clone()), _b(b->clone()), _stray(NULL) {};

Pair::Pair(const Pair &p) : _a(p._a->clone()), _b(p._b->clone()), _stray(NULL) {};

Pair::~Pair() { 
	delete _a; 
	delete _b; 
	delete _stray;
};

void Pair::print() const
{
	std::cout << "(";
	_a->print();
	std::cout << ", ";
	_b->print();
	std::cout << ")";
}

void Pair::setStray(BasePair *stray) 
{
	_stray = stray; 
}

void Pair::setA(BasePair *a) 
{ 
	_a = a; 
}

void Pair::setB(BasePair *b) 
{ 
	_b = b; 
}

BasePair* Pair::getA() const 
{ 
	return _a; 
}

BasePair* Pair::getB() const 
{ 
	return _b; 
}

BasePair* Pair::getStray() const 
{ 
	return _stray; 
}

BasePair& Pair::operator=(const BasePair& p)
{
	if (this == &p)
		return *this;
	delete _a;
	delete _b;
	delete _stray;
	const Pair* pair = dynamic_cast<const Pair*>(&p);
	if (pair) {
		_a = pair->getA().clone();
		_b = pair->getB().clone();
		_stray = pair->_stray ? pair->_stray->clone() : NULL;
	}
	return *this;
}

bool Pair::operator==(const BasePair* p) const
{
	const Pair* pair = dynamic_cast<const Pair*>(&p);
	if (pair) {
		return (*_a == pair->getA());
	}
	return false;
}

bool Pair::operator!=(const BasePair* p) const
{
	const Pair* pair = dynamic_cast<const Pair*>(&p);
	if (pair) {
		return (*_a != pair->getA());
	}
	return false;
}

bool Pair::operator<(const BasePair* p) const
{
	const Pair* pair = dynamic_cast<const Pair*>(&p);
	if (pair) {
		return (*_a < pair->getA());
	}
	return false;
}

bool Pair::operator>(const BasePair* p) const
{
	const Pair* pair = dynamic_cast<const Pair*>(&p);
	if (pair) {
		return (*_a > pair->getA());
	}
	return false;
}

bool Pair::operator<=(const BasePair* p) const
{
	const Pair* pair = dynamic_cast<const Pair*>(&p);
	if (pair) {
		return (*_a <= pair->getA());
	}
	return false;
}

bool Pair::operator>=(const BasePair* p) const
{
	const Pair* pair = dynamic_cast<const Pair*>(&p);
	if (pair) {
		return (*_a >= pair->getA());
	}
	return false;
}

void Pair::sort()
{
	if (*_a < *_b)
	{
		std::swap(_a, _b);
	}
}
