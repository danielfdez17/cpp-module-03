#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap patata("patata");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.guardGate();
	patata.takeDamage(5);
	patata.attack("Square Pants Sponge Bob");
	patata.beRepaired(10);
	patata.attack("Square Pants Sponge Bob");
	patata.attack("Square Pants Sponge Bob");
	patata.guardGate();
	return 0;
}