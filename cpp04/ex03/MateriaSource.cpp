#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _count(0)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		_count = rhs._count;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (_count < 4)
	{
		_inventory[_count] = m;
		_count++;
	}
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return NULL;
}

/* int MateriaSource::getCount() const */
/* { */
/* 	return _count; */
/* } */
