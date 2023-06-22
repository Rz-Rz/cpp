#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		void attack(std::string const & target);
		void guardGate(void);

		ScavTrap & operator=(ScavTrap const & rhs);
};
#endif
