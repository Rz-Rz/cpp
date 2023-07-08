#include "Serializer.hpp"
#include <iostream>


int main()
{
	Data data = {10, 20.5f, 'z'};
	Serializer serializer;
	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	if (ptr == &data) {
		std::cout << "The original and deserialized pointers are identical." << std::endl;
	} else {
		std::cout << "The original and deserialized pointers are not identical." << std::endl;
	}
}
