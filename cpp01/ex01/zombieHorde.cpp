#include "Zombie.hpp"
#include <sstream>

Zombie** zombieHorde(int N, std::string name)
{
    Zombie** horde = new Zombie*[N];

    for (int i = 0; i < N; i++)
    {
        std::stringstream zombieName;
        zombieName << name << "_" << (i + 1);
        horde[i] = new Zombie(zombieName.str());
    }

    return horde;
}
