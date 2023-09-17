#include "IterativePair.hpp"
#include <memory> // for std::auto_ptr
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

void	printDuration(std::clock_t time, std::string container, unsigned long range)
{
	std::cout << "Time to process a range of " << range << " elements ";
	std::cout << "with std::" << container << " : ";
	std::cout << ((double) time / (CLOCKS_PER_SEC / 1000000) ) << " us" << std::endl;
}

template <typename V>
typename std::vector<V>::iterator binarySearch(typename std::vector<V>::iterator first, typename std::vector<V>::iterator last, V val)
{
    while (std::distance(first, last) >= 2)
    {
        typename std::vector<V>::iterator middle = first + std::distance(first, last) / 2;
        if (val < *middle)
            last = middle; // Update last to middle, search in the left part
        else
            first = middle; // Update first to middle, search in the right part
    }
    if (val < *first)
        return first;
    else
        return last;
}

int Jacobsthal_n(int Jacobsthal_n_1, int Jacobsthal_n_2)
{
  // Jacobsthal suite : t_n = t_n-1 + 2*t_n-2
  return (Jacobsthal_n_1 + 2 * Jacobsthal_n_2);
}

std::vector <IterativePair<int> > insertPairs2(std::vector<IterativePair<int> > &v, IterativePair<int> *s)
{
		size_t J_upper = 1;
		size_t J_lower = 1;
		size_t tmp = J_lower;
    IterativePair<int> p1;
    IterativePair<int> p2;
    std::vector<IterativePair<int> > main_chain;
    std::vector<IterativePair<int> >::iterator pos;

    //Insert First Pair with no Comparison
    if (v[0].getPairs(p1, p2)) {
      main_chain.push_back(p2);
      main_chain.push_back(p1);
    }

    //Insert Pairs with Comparison
    while (J_upper < v.size())
    {
      // set Jacobsthal values
      tmp = J_lower;
      J_lower = J_upper;
      J_upper = std::min(Jacobsthal_n(J_lower, tmp), static_cast<int>(v.size()));

      // Add all As to the main_chain
      for (size_t i = J_lower; i < J_upper; i++)
      {
        if (v[i].getPairs(p1, p2)) {
          main_chain.push_back(p1);
        }
      }
      //Insert stray if there is one
      // Then add all Bs to the main_chain with binarySearch
      for (size_t i = J_lower; i < J_upper; i++)
      {
        if (v[i].getPairs(p1, p2)) {
          pos = binarySearch<IterativePair<int> >(main_chain.begin(), main_chain.end(), p2);
          main_chain.insert(pos, p2);
        }
      }
    }
    if (s != NULL)
    {
        pos = binarySearch<IterativePair<int> >(main_chain.begin(), main_chain.end(), *s);
        main_chain.insert(pos, *s);
      // }
    }
      return main_chain;
}

void cleanupDynamicPairs(std::vector<IterativePair<int> >& dynamicMemoryPairs) {
  for (std::vector<IterativePair<int> >::iterator it = dynamicMemoryPairs.begin(); it != dynamicMemoryPairs.end(); ++it)
  {
    it->deleteP1();
    it->deleteP2();
  }
  // dynamicMemoryPairs.clear();
}

void cleanStrays(std::vector<IterativePair<int>* >& strays) {
  for (std::vector<IterativePair<int>* >::iterator it = strays.begin(); it != strays.end(); ++it)
  {
    if (*it != NULL)
      delete *it;
  }
  // strays.clear();
}

void FordJohnsonSort(std::vector<int> &v)
{
  std::vector<IterativePair<int> > pairs;
  std::vector<IterativePair<int> > tmp;
  std::vector<IterativePair<int>* > strays;
  std::vector<IterativePair<int> > dynamicMemoryPairs;
  IterativePair<int> p1;

  std::cout << " Pairs at the beginning ---" << std::endl;
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
  {
    IterativePair<int> p(*it);
    p.print();
    pairs.push_back(p);
  }
  std::cout << std::endl << " --- Pairs at the beginning" << std::endl;

  size_t size = pairs.size();
  while (size != 1)
  {
    for (size_t it = 0; it < (size - (size % 2)); it += 2) {
      IterativePair<int> p(pairs[it], pairs[it + 1]);
      tmp.push_back(p);
      dynamicMemoryPairs.push_back(tmp.back());
    }
    std::cout << "Pairs at the end of the loop ---" << std::endl;
    for (std::vector<IterativePair<int> >::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
      it->print_all();
      std::cout << " ";;
    }
    std::cout << "stray: ";
    if (size % 2) {
      IterativePair<int> *p = new IterativePair<int>(pairs[size - 1]);
      strays.push_back(p);
      p->print_all();
    }
    else { strays.push_back(NULL); }
    std::cout << std::endl << " --- Pairs at the end of the loop" << std::endl;
    pairs = tmp;
    tmp.clear();
    size = pairs.size();
  }
  p1 = pairs[0];
  std::cout << std::endl << std::endl;
  for (int i = strays.size() - 1; i >= 0; i--)
  {
    tmp.clear();
    std::cout << "I for strays is " << i << " sending stray: ";
    if (strays[i] != NULL)
    {
      strays[i]->print_all();
    }
    else { std::cout << "NULL"; }
    std::cout << std::endl;
    tmp = insertPairs2(pairs, strays[i]);
    pairs = tmp;
    std::cout << "Inserted Pairs ---" << std::endl;
    for (std::vector<IterativePair<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
      it->print_all();
      std::cout << " ";;
    }
    std::cout << std::endl << " --- Inserted Pairs" << std::endl; 
  }
  std::cout << " Final Result " << std::endl;
    for (std::vector<IterativePair<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
      it->print_all();
      std::cout << std::endl;
    }
    cleanupDynamicPairs(dynamicMemoryPairs);
    cleanStrays(strays);
}

int main(int ac, char *argv[])
{
  ToolBox t;

  try {
    if (ac == 1)
    {
      throw ToolBox::ParsingErrorException();
      return 0;
    }
    t.parse(ac, argv);
  // int arr[] = {7, 8, 5, 9, 11, 0, 2, 1, 10, 3, 4, 6};
  // std::vector<int> v;
  // v.insert(v.end(), arr, arr + sizeof(arr)/sizeof(arr[0]));
    FordJohnsonSort(t.vect);
  } catch (ToolBox::ParsingErrorException &e) {
    std::cerr << e.what() << std::endl;
  } 
  return 0;
}
