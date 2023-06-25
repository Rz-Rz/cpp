#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		void makeSound() const;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;

		Dog &operator=(const Dog &rhs);

	private:
		Brain *brain;
};
#endif
