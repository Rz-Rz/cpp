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
		//Getters Setters
		long double a() const;
		long double b() const;
    long double s() const;
    long double stray() const;
		void setValue(long double value);
    BasePair* getLeafA();
    BasePair* getLeafB();
    // Processed state to avoid duplicate processing
    bool a_processed_state() const;
    bool b_processed_state() const;
    bool s_processed_state() const;
    void a_was_processed();
    void b_was_processed();
    void s_was_processed();
    // 
    bool is_stray() const;

	
	private: 
		long double _value;
    bool _processed;
};
#endif
