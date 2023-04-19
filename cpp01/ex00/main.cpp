#include "Zombie.hpp"

int main()
{
    // Create a zombie on the heap using newZombie
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    // Delete the zombie created on the heap
    delete heapZombie;

    // Create a zombie on the stack using randomChump
    randomChump("StackZombie");

    return 0;
}
