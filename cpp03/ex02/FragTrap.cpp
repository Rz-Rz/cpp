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

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &rhs) {
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_attackDamage = rhs._attackDamage;
		_energyPoints = rhs._energyPoints;
	}
	return *this;
}
