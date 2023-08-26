#ifndef BASEPAIR_HPP
#define BASEPAIR_HPP
#include "SmartPointer.hpp"
//Base class declaration 
class BasePair {
	public: 
		BasePair() {}
		virtual void print() const = 0;
		virtual SmartPointer<BasePair> clone() const = 0; 
		virtual ~BasePair() {}
    virtual long double a() const = 0;
    virtual long double b() const = 0;
    virtual long double s() const = 0;
    virtual bool is_stray() const = 0;
	protected:
		BasePair(const BasePair &/*p*/) {};
		BasePair& operator=(const BasePair &p);
};
#endif
