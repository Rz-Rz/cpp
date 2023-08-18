#ifndef BASEPAIR_HPP
#define BASEPAIR_HPP
//Base class declaration 
class BasePair {
	public: 
		BasePair() {}
		virtual void print() const = 0;
		virtual BasePair* clone() const = 0; 
		virtual ~BasePair() {}
	private:
		BasePair(const BasePair &p);
		BasePair& operator=(const BasePair &p);
};
#endif
