#include "FordJohnson.hpp"

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	ford_johnson(v);
	return 0;
}
