#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = NULL;
	*this = other;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}

void Dog::setIdea(int index, std::string idea) {
	if (index >= 0 && index < 100) {
		this->brain->ideas[index] = idea;
	} else {
		std::cout << "Invalid index. Please enter a value between 0 and 99." << std::endl;
	}
}

std::string Dog::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return this->brain->ideas[index];
	} else {
		std::cout << "Invalid index. Please enter a value between 0 and 99." << std::endl;
		return "";
	}
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete this->brain;
		this->brain = new Brain(*(rhs.brain));
	}
	return *this;
}
