#include <stdexcept>
#include <stdio.h>
#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

int main(int argc, char **argv)
{
  if (argc != 2) {
    std::cerr << "Error: One argument expected" << std::endl;
    return 1;
  }

  std::string input(argv[1]);
  std::istringstream iss(input);
  std::stack<double> stack;


  while (!iss.eof()) {
    if (std::isdigit(iss.peek()))
    {
      double number;
      iss >> number;
      stack.push(number);
    } 
    else if (std::isspace(iss.peek())) 
    {
      while (std::isspace(iss.peek()))
        iss.ignore();
    } 
    else 
    {
      char op;
      iss >> op;
      if (iss.eof())
        break;
      if (stack.size() < 2)
      {
        std::cerr << "Error: Not enough operand" << std::endl;
        return 1;
      }
      double b = stack.top(); stack.pop();
      double a = stack.top(); stack.pop();
      try {
        double result = calculate(a, b, op);
        stack.push(result);
      }
      catch (std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
      }
    }
  }

  if (stack.size() != 1)
  {
    std::cerr << "Error: Invalid RPN expression" << std::endl;
    return 1;
  }
  std::cout << stack.top() << std::endl;
  return 0;
}
