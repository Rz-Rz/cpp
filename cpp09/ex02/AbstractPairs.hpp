#ifndef ABSTRACT_PAIRS_HPP
#define ABSTRACT_PAIRS_HPP

#include "BasePair.hpp"
#include "SmartPointer.hpp"
#include <cstddef>
#include <iostream>

// Composite class declaration - Pair
class Pair : public BasePair {
	private: 
		Pair();
		SmartPointer<BasePair> _a;
		SmartPointer<BasePair> _b;
		SmartPointer<BasePair> _stray;
    long double _max;
    long double _min;

	public: 
		Pair(BasePair *a, BasePair *b);
		Pair(const Pair &p);
		~Pair();

		void print() const;
		SmartPointer<BasePair> clone() const;

		// Getters
		long double a() const;
		long double b() const;
		BasePair *stray() const;

		// Setters
		void setA(BasePair* a);
		void setB(BasePair* b);
		void setStray(BasePair* stray);

		// Operators
		BasePair &operator=(const BasePair& p);
		bool operator==(const Pair* p) const;
		bool operator!=(const Pair* p) const;
		bool operator<(const Pair* p) const;
		bool operator>(const Pair* p) const;
		bool operator<=(const Pair* p) const;
		bool operator>=(const Pair* p) const;

		// Useful
		void sort();
};
#endif
