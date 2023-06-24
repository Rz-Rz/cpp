#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = NULL;
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}

void Cat::setIdea(int index, std::string idea) {
	if (index >= 0 && index < 100) {
        this->brain->ideas[index] = idea;
    } else {
        std::cout << "Invalid index. Please enter a value between 0 and 99." << std::endl;
    }
}

std::string Cat::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return this->brain->ideas[index];
	} else {
		std::cout << "Invalid index. Please enter a value between 0 and 99." << std::endl;
		return "";
	}
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (this->brain != NULL)
			delete this->brain;
		this->brain = new Brain(*(rhs.brain));
	}
	return *this;
}
