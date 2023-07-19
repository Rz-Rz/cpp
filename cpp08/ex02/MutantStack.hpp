#include <stack>
#include <deque>
#include <stdexcept>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    const_iterator begin() const { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator end() const { return this->c.end(); }

    void pop() {
      if (this->empty()) {
        throw std::out_of_range("Stack is empty");
      }
      std::stack<T, std::deque<T> >::pop();
    }
    T& top() {
      if (this->empty()) {
        throw std::out_of_range("Stack is empty");
      }
      return std::stack<T, std::deque<T> >::top();
    }
};
