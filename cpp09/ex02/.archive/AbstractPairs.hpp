#ifndef ABSTRACT_PAIRS_HPP
#define ABSTRACT_PAIRS_HPP

#include "Stack.hpp"
#include "BasePair.hpp"
#include <vector>
#include "SmartPointer.hpp"
#include <cstddef>
#include <iostream>

// Composite class declaration - Pair
class Pair : public BasePair {
	private: 
		BasePair* _a;
		BasePair* _b;
		BasePair* _stray;
    long double _max;
    long double _min;

	public: 
		Pair();
		Pair(BasePair& a, BasePair& b);
		Pair(BasePair& a, BasePair& b, BasePair& stray);
		Pair(const Pair &p);
		~Pair();

		void print() const;

    BasePair* getLeafA() ;
    BasePair* getLeafB();

    bool a_processed_state() const;
    bool b_processed_state() const;
    bool s_processed_state() const;
    void a_was_processed();
    void b_was_processed();
    void s_was_processed();

		// Getters
		long double a() const;
		long double b() const;
    long double s() const;
		BasePair *stray() const;

    bool is_stray() const;

		// Setters
		void setA(BasePair* a);
		void setB(BasePair* b);
		void setStray(BasePair* stray);

		// Operators
		BasePair &operator=(const BasePair& p);
		bool operator==(const Pair& p) const;
		bool operator!=(const Pair& p) const;
		bool operator<(const Pair& p) const;
		bool operator>(const Pair& p) const;
		bool operator<=(const Pair& p) const;
		bool operator>=(const Pair& p) const;

		// Useful
		void sort();
};

std::ostream& operator<<(std::ostream& os, const Pair& p);
std::vector<long double> insertPairs(Stack<std::vector<SmartPointer<BasePair> > > &stack);
void ford_johnson(std::vector<long double> &unsorted_list);
void printMain(std::vector<long double> mainChain);
#endif
