#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	void highFivesGuys(void);

	FragTrap & operator=(FragTrap const & rhs);

protected :
	int _hitPoints;
	int _attackDamage;
	int _energyPoints;
};

#endif
