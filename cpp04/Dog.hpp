#include "Animal.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		void makeSound() const;

		Dog &operator=(const Dog &rhs);
};
#endif
