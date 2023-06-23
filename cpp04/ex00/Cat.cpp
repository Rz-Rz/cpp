#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}
