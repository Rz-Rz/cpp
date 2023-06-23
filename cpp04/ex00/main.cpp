#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	Dog *dog = new Dog();
	dog->makeSound();
	Dog *dog2 = new Dog(*dog);
	dog2->makeSound();


	delete meta;
	delete j;
	delete i;
	delete dog;
	delete dog2;

	return 0;
}
