#include "RPN.hpp"

double calculate(double a, double b, char op)
{
  switch (op)
  {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a*b;
    case '/':
      return a/b;
    default: throw std::runtime_error("Unknown operator");
  }
}
