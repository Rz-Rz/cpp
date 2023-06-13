#include <string>

class ClapTrap {

	public :
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(ClapTrap const & src);
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void setName(std::string name);
		std::string getName(void);
		int getAttackDamage(void);
		int getEnergyPoints(void);

		ClapTrap & operator=(ClapTrap const & rhs);

	private :
		std::string _name;
		int _hitPoints;
		int _attackDamage;
		int _energyPoints;
};
