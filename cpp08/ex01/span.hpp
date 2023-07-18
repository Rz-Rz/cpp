#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>

#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{ 
  private:
    unsigned int _N;
    std::vector<int> _vec;

  public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
      while (begin != end)
      {
        addNumber(*begin);
        ++begin;
      }
    }

};
#endif
