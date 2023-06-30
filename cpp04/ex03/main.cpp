#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	/* IMateriaSource* src = new MateriaSource(); */
	/* src->learnMateria(new Ice()); */
	/* src->learnMateria(new Cure()); */
	
	/* ICharacter* me = new Character("me"); */
	/* AMateria* tmp; */
	/* tmp = src->createMateria("ice"); */
	/* me->equip(tmp); */
	/* tmp = src->createMateria("cure"); */
	/* me->equip(tmp); */
	/* ICharacter* bob = new Character("bob"); */
	/* me->use(0, *bob); */
	/* me->use(1, *bob); */
	/* delete bob; */
	/* delete me; */
	/* delete src; */

	 MateriaSource* src = new MateriaSource();

    // learning Materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // creating Characters
    ICharacter* me = new Character("me");
    ICharacter* you = new Character("you");

    // equipping Materias
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    // using Materias
    me->use(0, *you);
    me->use(1, *you);

    // unequipping Materias
    me->unequip(0);
    me->unequip(1);

    delete me;
    delete you;
    delete src;

	return 0;	
}
