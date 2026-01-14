#include "ScavTrap.hpp"
#include <iostream>
int main(void)
{
	// {
	// 	std::cout << YELLOW "[INFO] ex00 tests---------------\n" RESET;
	// 	ClapTrap patata("patata");
	// 	patata.attack("Square Pants Sponge Bob");
	// 	patata.attack("Square Pants Sponge Bob");
	// 	patata.attack("Square Pants Sponge Bob");
	// 	patata.attack("Square Pants Sponge Bob");
	// 	patata.attack("Square Pants Sponge Bob");
	// 	patata.attack("Square Pants Sponge Bob");
	// 	patata.attack("Square Pants Sponge Bob");
	// 	patata.attack("Square Pants Sponge Bob");
	// 	patata.takeDamage(5);
	// 	patata.attack("Square Pants Sponge Bob");
	// 	patata.beRepaired(10);
	// 	patata.attack("Square Pants Sponge Bob");
	// 	patata.attack("Square Pants Sponge Bob");
	// }
	{
		std::cout << YELLOW "[INFO] ex01 tests---------------\n" RESET;
		ScavTrap scav("patata");
		scav.attack("Square Pants Sponge Bob");
		scav.attack("Square Pants Sponge Bob");
		scav.attack("Square Pants Sponge Bob");
		scav.attack("Square Pants Sponge Bob");
		scav.attack("Square Pants Sponge Bob");
		scav.attack("Square Pants Sponge Bob");
		scav.attack("Square Pants Sponge Bob");
		scav.attack("Square Pants Sponge Bob");
		scav.guardGate();
		scav.takeDamage(5);
		scav.attack("Square Pants Sponge Bob");
		scav.beRepaired(10);
		scav.attack("Square Pants Sponge Bob");
		scav.attack("Square Pants Sponge Bob");
		scav.guardGate();
	}
	return 0;
}