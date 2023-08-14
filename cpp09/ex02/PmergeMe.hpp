#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <queue>
#include <string>

typedef long long ll;

struct ComparePair {
  bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first > b.first;
  }
};

std::vector<ll> fillVector(int argc, char *argv[]);
ll __strtoll(std::string s);
void printVector(std::vector<ll> v);
void printVectorPair(std::vector<std::pair<ll, ll> > v);
void printPriorityQueue(std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll> >, ComparePair> pq); 

void printArray(int A[], int size);
void mergeSort(int array[], int l, int r);
void merge(int array[], int const left, int const mid, int const right);
void insertSort(int A[], int n);



#endif
