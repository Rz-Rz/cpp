#ifndef FORD_JOHNSON_HPP
#define FORD_JOHNSON_HPP
#include <vector>
#include "Pairs.hpp"
#include "BinarySearch.hpp"
#include "Stack.hpp"

void ford_johnson(std::vector<T> &v)
{
	Stack<std::vector<Pair<T> > > s;
	T *stray;

	// Create a while loop that will run until we have a list of one.
	while (v.size() >= 2)
	{
		// Create a new vector that will hold the pair.
		std::vector<Pair<T> > u(v.size() / 2);
		//save the stray if there is the need to.
		if (v.size() % 2 == 1)
			stray = &v.back();
		// Create a for loop that will iterate through the vector and make pair.
		for (unsigned long i = 0; i < v.size() / 2; i++)
		{
			// Create a pair that will hold the two values.
			Pair<T> p(v[i * 2], v[i * 2 + 1]);
			// Add the pair to the vector.
			u[i] = p;
		}
		//The vector is full of pairs, we can simulate the behaviour of a recursive call by pushing it in a stack.




	}

}




#endif
