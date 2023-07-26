#include "PmergeMe.hpp"
#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <limits>
#include <sstream>

typedef long long ll;

std::vector<ll> fillVector(int argc, char *argv[]) {
    std::vector<ll> v;
    for (int i = 1; i < argc; i++) {
      v.push_back(__strtoll(argv[i]));
      if (v[i] > std::numeric_limits<int>::max() || v[i] < std::numeric_limits<int>::min()) {
        std::cerr << "Error: integer overflow" << std::endl;
        exit(1);
      }
    }
    return v;
}

ll __strtoll(std::string s) {
  std::istringstream iss(s);
  ll num;
  iss >> num; 

  // Error checking
  if (iss.fail() || !iss.eof()) {
    std::cerr << "Error: invalid argument: " << s << std::endl;
    exit(1);
  }
  return num;
}

void printVector(std::vector<ll> v) {
    for (unsigned long i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void printVectorPair(std::vector<std::pair<ll, ll> > v) {
    for (unsigned long i = 0; i < v.size(); i++) {
        std::cout << "(" << v[i].first << ", " << v[i].second << ")" << std::endl;
    }
    std::cout << std::endl;
}

void printPriorityQueue(std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll> >, ComparePair> pq) {
    while (!pq.empty()) {
        std::cout << "(" << pq.top().first << ", " << pq.top().second << ")" << std::endl;
        pq.pop();
    }
    std::cout << std::endl;
}
