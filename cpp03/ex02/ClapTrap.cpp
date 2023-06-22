#include "ClapTrap.hpp"
#include <iostream>

void ClapTrap::attack(std::string const & target) {
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << getName() << " is out of energy!" << std::endl;
		return;
	}
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << getName() << " is dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << getName() << " is out of energy!" << std::endl;
		return;
	}
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << getName() << " is dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << getName() << " is repaired for " << amount << " points!" << std::endl;
	_hitPoints += amount;
	_energyPoints -= amount;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
}

int ClapTrap::getEnergyPoints(void) {
	return _energyPoints;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _attackDamage(0), _energyPoints(10) {
	std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &rhs) {
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_attackDamage = rhs._attackDamage;
		_energyPoints = rhs._energyPoints;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
}

std::string ClapTrap::getName(void) {
	return _name;
}

int ClapTrap::getAttackDamage(void) {
	return _attackDamage;
}