#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
#define CAT_HPP

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		void makeSound() const;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;

		Cat &operator=(const Cat &rhs);

	private:
		Brain *brain;
};
#endif
