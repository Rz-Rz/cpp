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
		Array(unsigned int size);
    Array(const Array& other);

    Array& operator=(const Array& other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;


};
#endif
