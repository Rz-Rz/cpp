#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	//ex00
	/* ClapTrap clap1("CL4P-TP"); */
	/* ClapTrap clap2("FR4G-TP"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap1.attack("Clap2"); */
	/* clap2.takeDamage(0); */
	/* clap2.takeDamage(0); */
	/* clap2.takeDamage(0); */
	/* clap2.takeDamage(0); */
	/* clap2.takeDamage(0); */
	/* clap2.takeDamage(0); */
	/* clap2.takeDamage(0); */
	/* clap2.takeDamage(0); */
	/* clap2.takeDamage(0); */
	/* clap2.takeDamage(0); */
	/* clap2.takeDamage(9); */
	/* clap2.beRepaired(9); */
	/* clap2.takeDamage(10); */
	/* clap2.beRepaired(9); */

	//ex01
	ScavTrap scav1("SC4V-TP");
	scav1.getName();
	std::cout << "ScavTrap has " << scav1.getAttackDamage() << " attack damage points." << std::endl;
	std::cout << "ScavTrap has " << scav1.getEnergyPoints() << " energy points." << std::endl;
	scav1.guardGate();

    return 0;

}
