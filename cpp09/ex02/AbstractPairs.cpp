#include "AbstractPairs.hpp"

Pair::Pair() : _a(NULL), _b(NULL), _stray(NULL) {};

Pair::Pair(BasePair *a, BasePair *b) : _a(a->clone()), _b(b->clone()), _stray(NULL) {
  sort();
};

Pair::Pair(BasePair *a, BasePair *b, BasePair *_stray) : _a(a->clone()), _b(b->clone()), _stray(_stray->clone()) {
  sort();
};

Pair::Pair(const Pair &p) : BasePair(p), _a(p._a->clone()), _b(p._b->clone()), _stray(NULL), _max(p._max), _min(p._min) {};

Pair::~Pair() { 
}

void Pair::print() const
{
  std::cout << "( " << _max << " , " << _min << " )";
  if (_stray.operator->() != NULL)
    std::cout << " stray: " << _stray->a();
  std::cout << std::endl;
}

bool Pair::is_stray() const
{
  return _stray.operator->() != NULL;
}

bool Pair::a_processed_state() const
{
  return _a->a_processed_state();
}

bool Pair::b_processed_state() const
{
  return _b->b_processed_state();
}

void Pair::a_was_processed()
{
  _a->a_was_processed();
}

void Pair::b_was_processed()
{
  _b->b_was_processed();
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

SmartPointer<BasePair> Pair::clone() const {
  return SmartPointer<BasePair>(new Pair(*this));
}

long double Pair::a() const 
{ 
  return _max;
}
long double Pair::b() const 
{ 
  return _min;
}

long double Pair::s() const 
{ 
  return _stray->a();
}

BasePair *Pair::stray() const 
{ 
	return _stray.get();
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

bool Pair::operator==(const Pair& p) const
{
		return (_max == p.a());
}

bool Pair::operator!=(const Pair& p) const
{
		return (_max != p.a());
}

bool Pair::operator<(const Pair& p) const
{
		return (_max < p.a());
}

bool Pair::operator>(const Pair& p) const
{
		return (_max > p.a());
}

bool Pair::operator<=(const Pair& p) const
{
		return (_max <= p.a());
}

bool Pair::operator>=(const Pair& p) const
{
		return (_max >= p.a());
}

void Pair::sort()
{
  if (_a.operator->()->a() < _b.operator->()->a())
  {
    std::swap(_a, _b);
  }
  _max = _a->a(); // Update _greatest
  _min = _b->a(); // Update _smallest
}

std::ostream& operator<<(std::ostream& os, const Pair& p) {
  os << "( " << p.a() << " , " << p.b() << " )";
  return os;
}

