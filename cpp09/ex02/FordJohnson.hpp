#ifndef FORD_JOHNSON_HPP
#define FORD_JOHNSON_HPP
#include <vector>
#include "Pairs.hpp"
#include "BinarySearch.hpp"

void ford_johnson(std::vector<T> &v)
{
	T *stray;

	while (v.size() >= 2)
	{
		std::vector<Pair<T> > u(v.size() / 2);
		if (v.size() % 2 == 1)
			stray = &v.back();


	}

}




#endif
