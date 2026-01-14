#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap patata("patata");
	ClapTrap copia = patata;
	std::cout << copia;;
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.highFivesGuys();
	patata.takeDamage(5);
	patata.attack("Square Pants Sponge Bob");
	patata.beRepaired(10);
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.highFivesGuys();
	return 0;
}