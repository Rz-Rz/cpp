#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap(void);
		void whoAmI(void);
		void attack(std::string const & target);
		int getAttackDamage(void);
		int getEnergyPoints(void);
		int getHitPoints(void);

		DiamondTrap & operator=(DiamondTrap const & rhs);

	private:
		std::string _name;
};

