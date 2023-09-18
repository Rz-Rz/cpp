#ifndef FORD_JOHNSON_HPP
#define FORD_JOHNSON_HPP
#include <vector>
#include "Pairs.hpp"
#include "BinarySearch.hpp"
#include "Stack.hpp"

template <typename T>
void ford_johnson(std::vector<T> &v)
{
	Stack<std::vector<Pair<T> > > s;
	T *stray;
	int stop = v.size();
	// Create a while loop that will run until we have a list of one.
	while (stop >= 2)
	{
		std::cout << "Hello++" << std::endl;
		// Create a new vector that will hold the pair.
		std::vector<T>  u(v.size() / 2);
		//save the stray if there is the need to.
		if (v.size() % 2 == 1)
			stray = &v.back();
		Pair<T> p;
		// Create a for loop that will iterate through the vector and make pair.
		for (unsigned long i = 0; i < v.size() / 2; i++)
		{
			// Create a pair that will hold the two values.
			p = Pair<T>(v[i * 2], v[i * 2 + 1]);
			// store the stray in the last pair of the vector if there is the need to.
			if (v.size() % 2 == 1 && i == v.size() / 2 - 1)
				p.setStray(stray);
			// Add the pair to the vector.
			u[i] = p;
		}
		v = u;
		stop /= 2;
		//The vector is full of pairs, we can simulate the behaviour of a recursive call by pushing it in a stack.
		s.push(u);
	}
	std::cout << "Hello" << std::endl;
	s.printStack();
}




#endif
