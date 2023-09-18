#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>


int Jacobsthal_n(int Jacobsthal_n_1, int Jacobsthal_n_2)
{
	// Jacobsthal suite : t_n = t_n-1 + 2*t_n-2
	return (Jacobsthal_n_1 + 2 * Jacobsthal_n_2);
}

//  -------------------------  Vector ----------------------------------------- //
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
		// Then add all Bs to the main_chain with binarySearch
		for (size_t i = J_lower; i < J_upper; i++)
		{
			if (v[i].getPairs(p1, p2)) {
				pos = binarySearch<IterativePair<int> >(main_chain.begin(), main_chain.end(), p2);
				main_chain.insert(pos, p2);
			}
		}
	}
	//Insert stray if there is one
	if (s != NULL)
	{
		pos = binarySearch<IterativePair<int> >(main_chain.begin(), main_chain.end(), *s);
		main_chain.insert(pos, *s);
	}
	return main_chain;
}

void print_iterative_pair(std::vector<IterativePair<int> > &v)
{
	std::cout << "After: ";
	for (std::vector<IterativePair<int> >::iterator it = v.begin(); it != v.end(); ++it)
	{
		it->print_all();
		std::cout << " ";
	}
	std::cout << std::endl;
}

void cleanupDynamicPairs(std::vector<IterativePair<int> >& dynamicMemoryPairs) {
	for (std::vector<IterativePair<int> >::iterator it = dynamicMemoryPairs.begin(); it != dynamicMemoryPairs.end(); ++it)
	{
		it->deleteP1();
		it->deleteP2();
	}
}

void cleanStrays(std::vector<IterativePair<int>* >& strays) {
	for (std::vector<IterativePair<int>* >::iterator it = strays.begin(); it != strays.end(); ++it)
	{
		if (*it != NULL)
			delete *it;
	}
}

void rec_simulation_pairs(std::vector<int> &v, std::vector<IterativePair<int> > &pairs, std::vector<IterativePair<int> > &dynamicMemoryPairs, std::vector<IterativePair<int>* > &strays)
{
	std::vector<IterativePair<int> > tmp;

#ifdef DEBUG
	std::cout << " Pairs at the beginning ---" << std::endl;
#endif
	// Create the first set of pairs
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		IterativePair<int> p(*it);
		p.print();
		pairs.push_back(p);
	}
	std::cout << std::endl;
#ifdef DEBUG
	std::cout << std::endl << " --- Pairs at the beginning" << std::endl;
#endif
	// Run until only one pair is left
	size_t size = pairs.size();
	while (size != 1)
	{
		for (size_t it = 0; it < (size - (size % 2)); it += 2) {
			IterativePair<int> p(pairs[it], pairs[it + 1]);
			tmp.push_back(p);
			dynamicMemoryPairs.push_back(tmp.back());
		}
#ifdef DEBUG
		std::cout << "Pairs at the end of the loop ---" << std::endl;
		for (std::vector<IterativePair<int> >::iterator it = tmp.begin(); it != tmp.end(); ++it)
		{
			it->print_all();
			std::cout << " ";;
		}
		std::cout << "stray: ";
#endif
		if (size % 2) {
			IterativePair<int> *p = new IterativePair<int>(pairs[size - 1]);
			strays.push_back(p);
#ifdef DEBUG
			p->print_all();
#endif
		}
		else { strays.push_back(NULL); }
#ifdef DEBUG
		std::cout << std::endl << " --- Pairs at the end of the loop" << std::endl;
#endif
		pairs = tmp;
		tmp.clear();
		size = pairs.size();
	}
}

void FordJohnsonSort(std::vector<int> &v)
{
	std::vector<IterativePair<int> > pairs;
	std::vector<IterativePair<int> > tmp;
	std::vector<IterativePair<int>* > strays;
	std::vector<IterativePair<int> > dynamicMemoryPairs;

	rec_simulation_pairs(v, pairs, dynamicMemoryPairs, strays);
#ifdef DEBUG
	std::cout << std::endl << std::endl;
#endif
	//Insert the pairs by levels of recursion
	for (int i = strays.size() - 1; i >= 0; i--)
	{
		tmp.clear();
#ifdef DEBUG
		std::cout << "I for strays is " << i << " sending stray: ";
		if (strays[i] != NULL)
		{
			strays[i]->print_all();
		}
		else { std::cout << "NULL"; }
		std::cout << std::endl;
#endif
		tmp = insertPairs2(pairs, strays[i]);
		pairs = tmp;
#ifdef DEBUG
		std::cout << "Inserted Pairs ---" << std::endl;
		for (std::vector<IterativePair<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			it->print_all();
			std::cout << " ";;
		}
		std::cout << std::endl << " --- Inserted Pairs" << std::endl << std::endl; 
#endif
	}
	//Print final result
	print_iterative_pair(pairs);
	//Clean the allocated memory
	cleanupDynamicPairs(dynamicMemoryPairs);
	cleanStrays(strays);
}

// --------------------------------------------------- Deque --------------------------------------------------- //

	template <typename V>
typename std::deque<V>::iterator binarySearch(typename std::deque<V>::iterator first, typename std::deque<V>::iterator last, V val)
{
	while (std::distance(first, last) >= 2)
	{
		typename std::deque<V>::iterator middle = first + std::distance(first, last) / 2;
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


std::deque<IterativePair<int> > insertPairs2(std::deque<IterativePair<int> > &v, IterativePair<int> *s)
{
	size_t J_upper = 1;
	size_t J_lower = 1;
	size_t tmp = J_lower;
	IterativePair<int> p1;
	IterativePair<int> p2;
	std::deque<IterativePair<int> > main_chain;
	std::deque<IterativePair<int> >::iterator pos;

	// Insert First Pair with no Comparison
	if (v[0].getPairs(p1, p2)) {
		main_chain.push_back(p2);
		main_chain.push_back(p1);
	}

	// Insert Pairs with Comparison
	while (J_upper < v.size())
	{
		tmp = J_lower;
		J_lower = J_upper;
		J_upper = std::min(Jacobsthal_n(J_lower, tmp), static_cast<int>(v.size()));

		for (size_t i = J_lower; i < J_upper; i++)
		{
			if (v[i].getPairs(p1, p2)) {
				main_chain.push_back(p1);
			}
		}

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
	}

	return main_chain;
}

void print_iterative_pair(std::deque<IterativePair<int> > &v)
{
	std::cout << "After: ";
	for (std::deque<IterativePair<int> >::iterator it = v.begin(); it != v.end(); ++it)
	{
		it->print_all();
		std::cout << " ";
	}
	std::cout << std::endl;
}

void cleanupDynamicPairs(std::deque<IterativePair<int> >& dynamicMemoryPairs) {
	for (std::deque<IterativePair<int> >::iterator it = dynamicMemoryPairs.begin(); it != dynamicMemoryPairs.end(); ++it)
	{
		it->deleteP1();
		it->deleteP2();
	}
}

void cleanStrays(std::deque<IterativePair<int>*>& strays) {
	for (std::deque<IterativePair<int>*>::iterator it = strays.begin(); it != strays.end(); ++it)
	{
		if (*it != NULL)
			delete *it;
	}
}

void rec_simulation_pairs(std::deque<int> &v, std::deque<IterativePair<int> > &pairs, std::deque<IterativePair<int> > &dynamicMemoryPairs, std::deque<IterativePair<int>* > &strays)
{
	std::deque<IterativePair<int> > tmp;

#ifdef DEBUG
	std::cout << " Pairs at the beginning ---" << std::endl;
#endif
	// Create the first set of pairs
	for (std::deque<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		IterativePair<int> p(*it);
		pairs.push_back(p);
	}
#ifdef DEBUG
	std::cout << std::endl << " --- Pairs at the beginning" << std::endl;
#endif
	// Run until only one pair is left
	size_t size = pairs.size();
	while (size != 1)
	{
		for (size_t it = 0; it < (size - (size % 2)); it += 2) {
			IterativePair<int> p(pairs[it], pairs[it + 1]);
			tmp.push_back(p);
			dynamicMemoryPairs.push_back(tmp.back());
		}
#ifdef DEBUG
		std::cout << "Pairs at the end of the loop ---" << std::endl;
		for (std::deque<IterativePair<int> >::iterator it = tmp.begin(); it != tmp.end(); ++it)
		{
			it->print_all();
			std::cout << " ";;
		}
		std::cout << "stray: ";
#endif
		if (size % 2) {
			IterativePair<int> *p = new IterativePair<int>(pairs[size - 1]);
			strays.push_back(p);
#ifdef DEBUG
			p->print_all();
#endif
		}
		else { strays.push_back(NULL); }
#ifdef DEBUG
		std::cout << std::endl << " --- Pairs at the end of the loop" << std::endl;
#endif
		pairs = tmp;
		tmp.clear();
		size = pairs.size();
	}
}

void FordJohnsonSort(std::deque<int> &v)
{
	std::deque<IterativePair<int> > pairs;
	std::deque<IterativePair<int> > tmp;
	std::deque<IterativePair<int>* > strays;
	std::deque<IterativePair<int> > dynamicMemoryPairs;

	rec_simulation_pairs(v, pairs, dynamicMemoryPairs, strays);
#ifdef DEBUG
	std::cout << std::endl << std::endl;
#endif
	//Insert the pairs by levels of recursion
	for (int i = strays.size() - 1; i >= 0; i--)
	{
		tmp.clear();
#ifdef DEBUG
		std::cout << "I for strays is " << i << " sending stray: ";
		if (strays[i] != NULL)
		{
			strays[i]->print_all();
		}
		else { std::cout << "NULL"; }
		std::cout << std::endl;
#endif
		tmp = insertPairs2(pairs, strays[i]);
		pairs = tmp;
#ifdef DEBUG
		std::cout << "Inserted Pairs ---" << std::endl;
		for (std::deque<IterativePair<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			it->print_all();
			std::cout << " ";;
		}
		std::cout << std::endl << " --- Inserted Pairs" << std::endl << std::endl; 
#endif
	}
	//Print final result
	// print_iterative_pair(pairs);
	//Clean the allocated memory
	cleanupDynamicPairs(dynamicMemoryPairs);
	cleanStrays(strays);
}

int main(int ac, char *argv[])
{
	PmergeMe t;

	try {
		if (ac == 1)
		{
			throw PmergeMe::ParsingErrorException();
			return 0;
		}
		t.start();
		t.parse(ac, argv);
		t.setParseTime(t.elapsed());
		t.reset();
		FordJohnsonSort(t.vect);
		t.printDuration(t.elapsed(), "vector", t.vect.size());
		t.reset();
		FordJohnsonSort(t.deq);
		t.printDuration(t.elapsed(), "deque",  t.deq.size());
	} catch (PmergeMe::ParsingErrorException &e) {
		std::cerr << e.what() << std::endl;
	} 
	return 0;
}
