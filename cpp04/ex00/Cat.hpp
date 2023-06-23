#include "Animal.hpp"

#ifndef CAT_HPP
#define CAT_HPP

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		void makeSound() const;

		Cat &operator=(const Cat &rhs);
};
#endif
