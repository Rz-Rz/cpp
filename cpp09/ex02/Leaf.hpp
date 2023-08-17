#ifndef LEAF_HPP
#define LEAF_HPP
#include "BasePair.hpp"
// Leaf class declaration - Value Holder
class Leaf : public BasePair {
	public: 
		//Constructors Destructors
		Leaf();
		Leaf(long double value);
		Leaf(const Leaf &l);
		~Leaf();

		void print() const;
		BasePair *clone() const;
	
	private: 
		long double _value;
};
#endif
