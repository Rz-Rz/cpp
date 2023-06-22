#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : public ClapTrap {
public:
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	void highFivesGuys(void);

	FragTrap & operator=(FragTrap const & rhs);

private:
	std::string _name;
	int _hitPoints;
	int _attackDamage;
	int _energyPoints;
};

#endif
