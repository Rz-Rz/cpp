#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap (std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap (FragTrap const & src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap (void) {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << getName() << " says: High five!" << std::endl;
}
