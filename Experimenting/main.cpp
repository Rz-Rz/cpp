#include "merge_insertion_sort.h"

int main()
{
  long double arr[] = {7, 8, 5, 9, 11, 0, 2, 1, 10, 3, 4, 6};
  std::vector<long double> v;
  v.insert(v.end(), arr, arr + sizeof(arr)/sizeof(arr[0]));
	merge_insertion_sort_impl(v);
}
