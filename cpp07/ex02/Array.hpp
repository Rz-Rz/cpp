template <typename T>

#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array
{
	private:
		unsigned int _size;
		T* _array;


	public:
		Array();
		Array(unsigned int n);
    Array(const Array& other);
    ~Array(); 

    Array& operator=(const Array& other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    size_t size() const;
};

#include "Array.tpp"
#endif
