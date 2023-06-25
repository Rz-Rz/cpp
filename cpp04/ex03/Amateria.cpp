#include "Amateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}
