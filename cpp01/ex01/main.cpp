#include "Zombie.hpp"

Zombie** zombieHorde(int N, std::string name);

int main()
{
    int numZombies = 10;
    Zombie** horde = zombieHorde(numZombies, "Walker");

    for (int i = 0; i < numZombies; i++)
    {
        horde[i]->announce();
    }
	for (int i = 0; i < numZombies; i++)
	{
		delete horde[i];
	}
	delete[] horde;
    return 0;
}
