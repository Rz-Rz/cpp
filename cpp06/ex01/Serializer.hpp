#include <stdint.h>

class Data
{
	public:
		int a;
		float b;
		char c;
};

class Serializer
{
	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);

		static  uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
