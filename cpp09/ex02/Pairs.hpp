#ifndef PAIRS_HPP
#define PAIRS_HPP
#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
class Pair
{
  private:  
    T* _a; 
    T* _b;
	T* _stray;

  public:
    // Constructors/Desctructors
    Pair<T>();
    Pair<T>(T& a, T& b);
    Pair<T>(const Pair<T>& p);
    ~Pair<T>();

    // Getters
    T& getA() const;
    T& getB() const;
	T* getStray() const;

    // Setters
    void setA(T& a);
    void setB(T& b);
	void setStray(T* stray);

    // Operators
    Pair<T>& operator=(const Pair<T>& p);
    bool operator==(const Pair<T>& p) const;
    bool operator!=(const Pair<T>& p) const;
    bool operator<(const Pair<T>& p) const;
    bool operator>(const Pair<T>& p) const;
    bool operator<=(const Pair<T>& p) const;
    bool operator>=(const Pair<T>& p) const;

	// Useful
	void sort();
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Pair<T>& p);

#include "Pairs.tpp"
#endif
