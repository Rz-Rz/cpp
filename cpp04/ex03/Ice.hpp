#include "string"
#include "Amateria.hpp"

#ifndef ICE_HPP
# define ICE_HPP

class Ice : public AMateria 
{
	public:
		Ice();
		Ice(Ice const & src);
		virtual ~Ice();
		Ice & operator=(Ice const & rhs);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};
#endif
