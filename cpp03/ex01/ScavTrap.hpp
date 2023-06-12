#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(ScavTrap const & src);
		void attack(std::string const & target);
		void guardGate(void);

		ScavTrap & operator=(ScavTrap const & rhs);
};
#endif
