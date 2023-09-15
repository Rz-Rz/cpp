#include <cstdlib>
#include <iterator>
#include <iostream>


template<typename V>
class IterativePair 
{
  private:
    V _value; 
    IterativePair<V> *_p1;
    IterativePair<V> *_p2;
    bool _alone;
    V getValue(void) const
    {
      if (_p1 != NULL && !_alone)
        return _p1->getValue();
      return _value;
    }

  public:
    IterativePair(void) : _value(0), _p1(NULL), _p2(NULL), _alone(true) {}
    IterativePair(V &value) : _value(value), _p1(NULL), _p2(NULL), _alone(true) {}
    IterativePair(IterativePair<V> &p1, IterativePair<V> &p2) : _value(0), _p1(new IterativePair<V> (p1)), _p2(new IterativePair<V> (p2)), _alone(false) {
      if (_p1->getValue() < _p2->getValue())
        std::swap(_p1, _p2);
    }
    IterativePair(const IterativePair<V> &p) : _value(p._value), _p1(p._p1), _p2(p._p2), _alone(p._alone) {}
    void print()
    {
      if (_alone)
        std::cout << _value << std::endl;
    }
   void print_all()
    {
      if ((!_p1 || !_p2) && _alone) {
        std::cout << _value;
        return;
      }
      if (_p1->_alone && _p2->_alone)
      {
        std::cout << "(";
        _p1->print_all();
        std::cout << ",";
        _p2->print_all();
        std::cout << ")";
      }
      else {
        std::cout << "{";
        _p1->print_all();
        _p2->print_all();
        std::cout << "}";
      }
    }
   bool getPairs(IterativePair<int> &p1, IterativePair<int> &p2)
   {
     if (!_p1 || !_p2)
       return false;
     p1 = *_p1;
     p2 = *_p2;
     return true;
   }

   //overload
   bool operator<(const IterativePair<V> &p) const
   {
     return getValue() < p.getValue();
   }
};
