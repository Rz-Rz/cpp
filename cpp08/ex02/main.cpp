#include "MutantStack.hpp"
#include <iostream>
#include <cassert>

int main()
{
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "size: " << mstack.size() << std::endl;


  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  MutantStack<int> nstack;
  assert(nstack.size() == 0);
  assert(nstack.empty() == true);

  MutantStack<int> lstack;
  lstack.push(5);
  assert(lstack.top() == 5);
  assert(lstack.size() == 1);

  try {
    lstack.pop();
    lstack.pop();
    lstack.pop();
    assert(false);  // Should not reach here
  } catch (const std::exception& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
try {
    int top = lstack.top();
    (void)top;
    assert(false);  // Should not reach here
  } catch (const std::exception& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  return 0;
}
