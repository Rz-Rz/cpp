//Base class declaration 
class BasePair {
	public: 
		BasePair() {}
		BasePair(const BasePair &p) {}
		BasePair& operator=(const BasePair &p) {}
		virtual void print() const = 0;
		virtual BasePair* clone() const = 0; 
		virtual ~BasePair() {}
}
