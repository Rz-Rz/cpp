#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << getName() << " is born!" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << getName() << " is dead!" << std::endl;
}

void ScavTrap::attack(std::string const & target) {
	if (_energyPoints <= 0) {
		std::cout << "ScavTrap " << getName() << " is out of energy!" << std::endl;
		return;
	}
	if (_hitPoints <= 0) {
		std::cout << "ScavTrap " << getName() << " is dead!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << getName() << " has entered Gate keeper mode." << std::endl;

}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &rhs) {
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_attackDamage = rhs._attackDamage;
		_energyPoints = rhs._energyPoints;
	}
	return *this;
}
