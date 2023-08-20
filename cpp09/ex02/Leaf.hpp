#ifndef LEAF_HPP
#define LEAF_HPP
#include "BasePair.hpp"
#include <iostream>
// Leaf class declaration - Value Holder
class Leaf : public BasePair {
	public: 
		//Constructors Destructors
		Leaf();
		Leaf(long double value);
		Leaf(const Leaf &l);
		~Leaf();

		void print() const;
		SmartPointer<BasePair> clone() const;
		//Getters Setters
		long double a() const;
		long double b() const;
    long double stray() const;
		void setValue(long double value);
	
	private: 
		long double _value;
};
#endif
