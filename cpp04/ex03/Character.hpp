#include <string> 
#include "Icharacter.hpp"
#include "Amateria.hpp"

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
		int _count;
		int _dropped;
		AMateria *_floor[20];
		Character();

	public:
		Character(std::string const & name);
		Character(Character const & src);
		virtual ~Character();
		Character & operator=(Character const & rhs);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
#endif
