#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	/* const Animal *meta = new Animal(); */
	/* const Animal *j = new Dog(); */
	/* const Animal *i = new Cat(); */


	/* std::cout << j->getType() << " " << std::endl; */
	/* std::cout << i->getType() << " " << std::endl; */
	/* std::cout << meta->getType() << " " << std::endl; */

	/* i->makeSound(); //will output the cat sound! */
	/* j->makeSound(); */
	/* meta->makeSound(); */

	/* Dog *dog = new Dog(); */
	/* dog->makeSound(); */
	/* Dog *dog2 = new Dog(*dog); */
	/* dog2->makeSound(); */


	/* const WrongAnimal *wrong = new WrongAnimal(); */
	/* const WrongAnimal *wrong2 = new WrongCat(); */
	/* std::cout << wrong->getType() << " " << std::endl; */
	/* std::cout << wrong2->getType() << " " << std::endl; */
	/* wrong->makeSound(); */
	/* wrong2->makeSound(); */

	/* delete meta; */
	/* delete j; */
	/* delete i; */
	/* delete dog; */
	/* delete dog2; */
	/* delete wrong; */
	/* delete wrong2; */

	Animal *animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}
	return 0;
}
