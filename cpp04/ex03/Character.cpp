#include "Character.hpp"

Character::Character(std::string const & name) : _name(name), _count(0)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = rhs._inventory[i]->clone();
		}
		_count = rhs._count;
	}
	return (*this);
}

