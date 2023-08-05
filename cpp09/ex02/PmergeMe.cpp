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

int merge_comp = 0;

void merge(int array[], int const left, int const mid, int const right)
{
  int const subArrayOne = mid - left + 1;
  int const subArrayTwo = right - mid;

  // Create temp arrays
  int *leftArray = new int[subArrayOne],
    *rightArray = new int[subArrayTwo];

  // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = array[left + i];
        std::cout << "LeftArray[" << i << "] is " << leftArray[i];
        std::cout << std::endl;

    }
    for (int j = 0; j < subArrayTwo; j++)
    {
        rightArray[j] = array[mid + 1 + j];
        std::cout << "RightArray[" << j << "] is " << rightArray[j];
        std::cout << std::endl;
    }

    std::cout << "SubArrayOne is " << subArrayOne << std::endl;
    std::cout << "SubArrayTwo is " << subArrayTwo << std::endl;
    int indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        merge_comp++;
        std::cout << "Merged Subarray: " << array[indexOfMergedArray];
        indexOfMergedArray++;
    }
    std::cout << std::endl;

    // Copy the remaining elements of left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int l, int r) {
  std::cout << "MergeSort: left is " << l << " and right is " << r << std::endl;
    if (l < r) {
        int m = (l + r)/2;
        std::cout << "MergeSort: mid is " << m << std::endl;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}


void insertSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    // Move elements of arr[0..i-1],
    // that are greater than key,
    // to one position ahead of their
    // current position
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--; 
    }
    arr[j + 1] = key;
  }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}
