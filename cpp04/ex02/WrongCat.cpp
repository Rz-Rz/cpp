#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat sound" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}
