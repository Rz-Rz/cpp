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


	Animal *abstract = new Animal();
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
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	Cat *cat = new Cat();
	Cat *cat2 = new Cat(*cat);
	delete cat;
	delete cat2;

	Cat *cat3 = new Cat();
	cat3->setIdea(0, "Hello");
	cat3->setIdea(1, "World");
	std::cout << cat3->getIdea(0) << std::endl;
	std::cout << cat3->getIdea(1) << std::endl;
	delete cat3;
	return 0;
}
