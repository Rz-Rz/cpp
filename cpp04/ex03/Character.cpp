#include "Character.hpp"

Character::Character(std::string const & name) : _name(name), _count(0), _dropped(0)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	for (int i = 0; i < 20; i++)
	{
		_floor[i] = NULL;
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
	for (int i = 0; i < 20; i++)
	{
		if (_floor[i])
			delete _floor[i];
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
		for (int i = 0; i < 20; i++)
		{
			if (_floor[i])
				delete _floor[i];
			_inventory[i] = rhs._inventory[i]->clone();
		}
		_count = rhs._count;
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (_count < 4)
	{
		_inventory[_count] = m;
		_count++;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		_floor[_dropped] = _inventory[idx];
		_dropped++;
		_inventory[idx] = NULL;
		_count--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx])
			_inventory[idx]->use(target);
	}
}
