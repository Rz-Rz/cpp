#ifndef ABSTRACT_PAIRS_HPP
#define ABSTRACT_PAIRS_HPP

#include "BasePair.hpp"

// Composite class declaration - Pair
class Pair : public BasePair {
	private: 
		BasePair *_a;
		BasePair *_b;
		BasePair *_stray;

	public: 
		Pair();
		Pair(BasePair *a, BasePair *b);
		Pair(const Pair &p);
		~Pair();

		void print() const;
		BasePair* clone() const;

		// Getters
		BasePair* getA() const;
		BasePair* getB() const;
		BasePair* getStray() const;

		// Setters
		void setA(BasePair* a);
		void setB(BasePair* b);
		void setStray(BasePair* stray);

		// Operators
		BasePair &operator=(const BasePair& p);
		bool operator==(const BasePair* p) const;
		bool operator!=(const BasePair* p) const;
		bool operator<(const BasePair* p) const;
		bool operator>(const BasePair* p) const;
		bool operator<=(const BasePair* p) const;
		bool operator>=(const BasePair* p) const;

		// Useful
		void sort();
};
#endif
