#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap patata("patata");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.takeDamage(5);
	patata.attack("Square Pants Sponge Bob");
	patata.beRepaired(10);
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	return 0;
}