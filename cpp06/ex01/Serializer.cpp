#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer()
{
	std::cout << "Serializer::Serializer()" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer::~Serializer()" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
	std::cout << "Serializer::Serializer(const Serializer& other)" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	std::cout << "Serializer& Serializer::operator=(const Serializer& other)" << std::endl;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
