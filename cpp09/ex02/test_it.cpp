#include "IterativePair.hpp"
#include <vector>
#include <queue>
#include <iostream>

static const unsigned long jacobsthal_diff[] = {
2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
1537228672809129216u, 3074457345618258432u, 6148914691236516864u
};

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

std::vector <IterativePair<int> > insertPairs(std::vector<IterativePair<int> > &v, IterativePair<int> *s)
{
  IterativePair<int> p1;
  IterativePair<int> p2;
  std::vector<IterativePair<int> > main_chain;
  std::vector<IterativePair<int>*> second_chain;

  if (v[0].getPairs(p1, p2)) {
    main_chain.push_back(p2);
    main_chain.push_back(p1);
  }
  for (std::vector<IterativePair<int> >::iterator it = v.begin() + 1; it != v.end(); ++it)
  {
    if (it->getPairs(p1, p2)) {
      main_chain.push_back(p1);
      second_chain.push_back(&p2);
    }
  }
  if (second_chain.size())
  {
    for (size_t i = 0; (jacobsthal_diff[i] - 1) < second_chain.size(); i++) {
      unsigned long j = jacobsthal_diff[i] - 1;
      std::vector<IterativePair<int> >::iterator pos;
      pos = binarySearch<IterativePair<int> >(main_chain.begin(), main_chain.begin() + j, *second_chain[j]);
      main_chain.insert(pos, *second_chain[j]);
      second_chain[j] = NULL;
    }
    for (size_t i = 0; i < second_chain.size(); i++) {
      if (second_chain[i] == NULL)
        continue;
      std::vector<IterativePair<int> >::iterator pos;
      pos = binarySearch<IterativePair<int> >(main_chain.begin(), main_chain.begin() + i, *second_chain[i]);
      main_chain.insert(pos, *second_chain[i]);
      second_chain[i] = NULL;
    }
  }
  if (s != NULL)
  {
    std::vector<IterativePair<int> >::iterator pos;
    pos = binarySearch<IterativePair<int> >(main_chain.begin(), main_chain.end(), *s);
    main_chain.insert(pos, *s);
  }
  return main_chain;
}


void FordJohnsonSort(std::vector<int> &v)
{
  std::vector<IterativePair<int> > pairs;
  std::vector<IterativePair<int> > tmp;
  std::vector<IterativePair<int>* > strays;

  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
  {
    IterativePair<int> p(*it);
    p.print();
    pairs.push_back(p);
  }

  size_t size = pairs.size();
  while (size != 1)
  {
    std::cout << "size: " << size << std::endl;
    for (size_t it = 0; it < (size - (size % 2)); it += 2) {
      IterativePair<int> p(pairs[it], pairs[it + 1]);
      tmp.push_back(p);
    }
    if (size % 2) {
      IterativePair<int> *p = new IterativePair<int>(pairs[size - 1]);
      strays.push_back(p);
    }
    else { strays.push_back(NULL); }
    pairs = tmp;
    tmp.clear();
    size = pairs.size();
  }
  pairs[0].print_all();

  // for (size_t i = strays.size(); i > 0; i--)
  // {
  tmp = insertPairs(pairs, strays[strays.size() - 1]);
  for (std::vector<IterativePair<int> >::iterator it = tmp.begin(); it != tmp.end(); ++it)
  {
    std::cout << "tmp: ";
    it->print_all();
  }

  // }
}









int main()
{
  int arr[] = {7, 8, 5, 9, 11, 0, 2, 1, 10, 3, 4, 6};
  std::vector<int> v;
  v.insert(v.end(), arr, arr + sizeof(arr)/sizeof(arr[0]));
  FordJohnsonSort(v);
  return 0;
}
