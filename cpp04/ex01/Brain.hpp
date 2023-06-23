#include <string>

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(Brain const &other);

		Brain &operator=(Brain const &other);
		std::string ideas[100];
};
#endif
