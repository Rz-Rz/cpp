#include <string>

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal &other);
		virtual void makeSound() const = 0;
		std::string getType() const;

		Animal &operator=(const Animal &other);

	protected:
		std::string type;
};
#endif
