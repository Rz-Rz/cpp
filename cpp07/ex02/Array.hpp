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

};
#endif
