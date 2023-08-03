#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <queue>
#include <limits>

typedef long long ll;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    std::cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    std::cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
  // std::vector<ll> v = fillVector(argc, argv);
  // unsigned long n = v.size();
  //
  // std::cout << "Original vector: " << std::endl;
  // printVector(v);
  //
  // std::sort(v.begin(), v.begin() + n/2); // first step of merge sort -- insertion sort
  // std::cout << "Sorted vector: " << std::endl;
  // printVector(v);
  //
  // std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll> >, ComparePair> pq;
  //
  // for (unsigned long i = 0; i < n/2; i++) {
  //   std::pair<ll, ll> p = std::make_pair(v[i], v[i + n/2]);
  //   pq.push(p);
  // }
  // if (n % 2 != 0) {
  //   std::pair<ll, ll> p = std::make_pair(v[n - 1], std::numeric_limits<ll>::max());
  //   pq.push(p);
  // }
  // std::cout << "Pairs: " << std::endl;
  // printPriorityQueue(pq);
  //
  // v.clear();
  // v.resize(n);
  //
  // unsigned long i = 0;
  // while (!pq.empty()) {
  //   std::pair<ll, ll> p = pq.top();
  //   pq.pop();
  //   v[i++] = p.first;
  //   if (p.second != std::numeric_limits<ll>::max()) {
  //     v[i++] = p.second;
  //   }
  // }
  // std::cout << "Merged vector: " << std::endl;
  // printVector(v);
  //
  //
  //
  return 0;
}
