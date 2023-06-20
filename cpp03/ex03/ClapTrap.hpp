#include <string>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap {

	public :
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void setName(std::string name);
		std::string getName(void);
		int getAttackDamage(void);
		int getEnergyPoints(void);

		ClapTrap & operator=(ClapTrap const & rhs);

	protected :
		std::string _name;
		int _hitPoints;
		int _attackDamage;
		int _energyPoints;
};
#endif
