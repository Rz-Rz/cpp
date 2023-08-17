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
		return this;
	delete _a;
	delete _b;
	delete _stray;
	_a = p._a->clone();
	_b = p._b->clone();
	_stray = p._stray ? p._stray->clone();

	return *this;
}

bool Pair::operator==(const BasePair* p) const
{
	return (*_a == p->getA());
}

bool Pair::operator!=(const BasePair* p) const
{
	return (*_a != p->getA());
}

bool Pair::operator<(const BasePair* p) const
{
	return (*_a < p->getA());
}

bool Pair::operator>(const BasePair* p) const
{
	return (*_a > p->getA());
}

bool Pair::operator<=(const BasePair* p) const
{
	return (*_a <= p->getA());
}

bool Pair::operator>=(const BasePair* p) const
{
	return (*_a >= p->getA());
}

void Pair::sort()
{
	if (*_a < *_b)
	{
		std::swap(_a, _b);
	}
}
