#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{

	ClapTrap clap1("CL4P-TP");
	ClapTrap clap2("FR4G-TP");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap1.attack("Clap2");
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(9);
	clap2.beRepaired(9);
	clap2.takeDamage(10);
	clap2.beRepaired(9);

    return 0;

}
