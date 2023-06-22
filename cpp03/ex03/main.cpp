#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
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
	/* ScavTrap scav1("SC4V-TP"); */
	/* scav1.getName(); */
	/* std::cout << "ScavTrap has " << scav1.getAttackDamage() << " attack damage points." << std::endl; */
	/* std::cout << "ScavTrap has " << scav1.getEnergyPoints() << " energy points." << std::endl; */
	/* scav1.guardGate(); */

	//ex02
	/* FragTrap frag1("FR4G-TP"); */
	/* frag1.attack("FR4G-TP"); */
	/* frag1.highFivesGuys(); */
	/* std::cout << "FragTrap has " << frag1.getAttackDamage() << " attack damage points." << std::endl; */
	/* std::cout << "FragTrap has " << frag1.getEnergyPoints() << " energy points." << std::endl; */
	/* frag1.takeDamage(10); */
	/* frag1.beRepaired(10); */
	/* FragTrap frag2 = frag1; */
	/* frag2.takeDamage(10); */
	/* frag2.beRepaired(10); */
	DiamondTrap diamond1("DI4M-TP");
	diamond1.whoAmI();
	diamond1.attack("DI4M-TP");
	diamond1.highFivesGuys();
	std::cout << "DiamondTrap has " << diamond1.getAttackDamage() << " attack damage points." << std::endl;
	std::cout << "DiamondTrap has " << diamond1.getEnergyPoints() << " energy points." << std::endl;
	std::cout << "DiamondTrap has " << diamond1.getHitPoints() << " hit points." << std::endl;
    return 0;
}
