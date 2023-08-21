#include "AbstractPairs.hpp"

Pair::Pair() : _a(NULL), _b(NULL), _stray(NULL) {};

Pair::Pair(BasePair *a, BasePair *b) : _a(a->clone()), _b(b->clone()), _stray(NULL) {
  sort();
};

Pair::Pair(const Pair &p) : BasePair(p), _a(p._a->clone()), _b(p._b->clone()), _stray(NULL) {};

Pair::~Pair() { 
}

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

long double Pair::a() const 
{ 
  return _max;
}
long double Pair::b() const 
{ 
  return _min;
}

BasePair* Pair::stray() const 
{ 
	return _stray.operator->();
}

BasePair& Pair::operator=(const BasePair& p)
{
	if (this == &p)
		return *this;
	const Pair* pair = dynamic_cast<const Pair*>(&p);
	if (pair) {
		_a = pair->_a->clone();
		_b = pair->_b->clone();
    if (pair->_stray.operator->() != NULL)
      _stray = pair->_stray->clone();
	}
  else {
    _stray = NULL;
  }
	return *this;
}

bool Pair::operator==(const Pair* p) const
{
		return (_max == p->a());
}

bool Pair::operator!=(const Pair* p) const
{
		return (_max != p->a());
}

bool Pair::operator<(const Pair* p) const
{
		return (_max < p->a());
}

bool Pair::operator>(const Pair* p) const
{
		return (_max > p->a());
}

bool Pair::operator<=(const Pair* p) const
{
		return (_max <= p->a());
}

bool Pair::operator>=(const Pair* p) const
{
		return (_max >= p->a());
}

void Pair::sort()
{
  if (_a.operator->()->a() < _b.operator->()->a())
  {
    std::swap(_a, _b);
  }
  _max = _a->a(); // Update _greatest
  _min = _b->b(); // Update _smallest
}
