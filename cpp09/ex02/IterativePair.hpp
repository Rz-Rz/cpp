#include <cstdlib>
#include <iterator>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>

template<typename V>
class IterativePair 
{
  private:
    V _value; 
    IterativePair<V> *_p1;
    IterativePair<V> *_p2;
    bool _alone;
    bool _hasDynamicMemory;
    V getValue(void) const
    {
      if (_p1 != NULL && !_alone)
        return _p1->getValue();
      return _value;
    }

  public:
    IterativePair(void) : _value(0), _p1(NULL), _p2(NULL), _alone(true), _hasDynamicMemory(false) {}
    IterativePair(V &value) : _value(value), _p1(NULL), _p2(NULL), _alone(true), _hasDynamicMemory(false) {}
    IterativePair(IterativePair<V> &p1, IterativePair<V> &p2) : _value(0), _p1(new IterativePair<V> (p1)), _p2(new IterativePair<V> (p2)), _alone(false), _hasDynamicMemory(true) {
      if (_p1->getValue() < _p2->getValue())
        std::swap(_p1, _p2);
    }
    IterativePair(const IterativePair<V> &p) : _value(p._value), _p1(p._p1), _p2(p._p2), _alone(p._alone), _hasDynamicMemory(false) {}
    ~IterativePair(void) {}
    void deleteP1() { delete _p1; _p1 = NULL; }
    void deleteP2() { delete _p2; _p2 = NULL; }
    void print()
    {
      if (_alone)
        std::cout << _value << " ";
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

class ToolBox : public std::exception {
  private:
    std::clock_t start_time;
    double parsing_time;

  public:
    std::vector<int> vect;
    std::deque<int> deq;

    ToolBox(void) {};
    ~ToolBox(void) throw() {}

    void start(void)
    {
      start_time = std::clock();
    }

    void reset(void)
    {
      start_time = std::clock();
    }

    double elapsed(void)
    {
      return (std::clock() - start_time);
    }

    void setParseTime(double t)
    {
      parsing_time = t;
    }

    void	printDuration(std::clock_t time, std::string container, unsigned long range)
    {
      std::cout << "Time to process a range of " << range << " elements ";
      std::cout << "with std::" << container << " : ";
      std::cout << ((double) (time + parsing_time ) / (CLOCKS_PER_SEC / 1000000) ) << " us" << std::endl;
    }

    void parse(int ac, char **av)
    {
      int	val;
      std::stringstream	iss;

      for (int i=1; i<ac; i++)
      {
        for (int j=0; av[i][j]!='\0'; j++)
        {
          if (!std::isdigit(av[i][j]) )
            throw ToolBox::ParsingErrorException();
        }
        iss.clear();
        iss << av[i];
        iss >> val;
        if (iss.fail())
          throw ToolBox::ParsingErrorException();
        vect.push_back(val);
        deq.push_back(val);
      }
    }

    class ParsingErrorException : public std::exception
  {
    public:
      virtual const char* what() const throw()
      {
        return "Parsing Error";
      }
  };
};

