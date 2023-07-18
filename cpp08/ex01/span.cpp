#include "span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _vec(other._vec)
{
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
  if (_vec.size() < _N)
    _vec.push_back(number);
  else
    throw std::length_error("Span is full");
}

Span& Span::operator=(const Span& other)
{
  if (this != &other)
  {
    this->_N = other._N;
    this->_vec = other._vec;
  }
  return *this;
}


int Span::shortestSpan() {
  if (_vec.size() < 2)
    throw std::length_error("Span is too short");
  std::vector<int> tmp(_vec);
  std::sort(tmp.begin(), tmp.end());
  int min = INT_MAX;
  for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
  {
    int diff = *(it + 1) - *it;
    if (diff < min)
      min = diff;
  }
  return min;
}

int Span::longestSpan() {
  if (_vec.size() < 2)
    throw std::length_error("Span is too short");
  std::vector<int> tmp(_vec);
  std::sort(tmp.begin(), tmp.end());
  return *(tmp.end() - 1) - *tmp.begin();
}
