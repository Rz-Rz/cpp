#include "Pairs.hpp"

template <typename T>
Pair<T>::Pair(): _a(0), _b(0), _stray(NULL) {}

template <typename T>
Pair<T>::Pair(T& a, T& b): _a(&a), _b(&b), _stray(NULL) {}

template <typename T>
Pair<T>::Pair(const Pair<T>& p): _a(p._a), _b(p._b), _stray(NULL) {}

template <typename T>
Pair<T>::~Pair() {}

template <typename T>
Pair<T>& Pair<T>::operator=(const Pair<T>& p)
{
  if (this != &p) {
    _a = p._a;
    _b = p._b;
  }
  return *this;
}

template <typename T>
void Pair<T>::sort()
{
  if (*_a < *_b) {
	  std::swap(*_a, *_b);
  }
}

// Getters
template <typename T>
T& Pair<T>::getA() const { 
  return *_a; 
}

template <typename T>
T& Pair<T>::getB() const { 
  return *_b; 
}

template <typename T>
T* Pair<T>::getStray() const {
  return _stray; 
}

// Setters
template <typename T>
void Pair<T>::setA(T& a) { 
  _a = &a;
}

template <typename T>
void Pair<T>::setB(T& b) { 
  _b = &b; 
}

template <typename T>
void Pair<T>::setStray(T* stray) { 
  _stray = stray; 
}

template <typename T>
bool Pair<T>::operator==(const Pair<T>& p) const
{
  return (*_a == *p._a);
}

template <typename T>
bool Pair<T>::operator!=(const Pair<T>& p) const 
{ 
  // return (*_a != *p._a);
  return !(*this == p);
}

template <typename T>
bool Pair<T>::operator<(const Pair<T>& p) const
{
  return (*_a < *p._a);
}

template <typename T>
bool Pair<T>::operator>(const Pair<T>& p) const
{
  return (*_a > *p._a);
}

template <typename T>
bool Pair<T>::operator<=(const Pair<T>& p) const
{
  return (*_a <= *p._a);
}

template <typename T>
bool Pair<T>::operator>=(const Pair<T>& p) const
{
  return (*_a >= *p._a);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Pair<T>& p)
{
  os << "(" << *(p.getA()) << ", " << *(p.getB()) << ")";
  return os;
}
