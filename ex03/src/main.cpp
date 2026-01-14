#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap patata("patata");
	std::cout << "attack damage: " << patata.getAttackDamage() << "\n";
	std::cout << "hit points: " << patata.getHitPoints() << "\n";
	std::cout << "energy points: " << patata.getEnergyPoints() << "\n";
	// patata.attack("Square Pants Sponge Bob");
	// patata.attack("Square Pants Sponge Bob");
	// patata.attack("Square Pants Sponge Bob");
	// patata.attack("Square Pants Sponge Bob");
	// patata.attack("Square Pants Sponge Bob");
	// patata.attack("Square Pants Sponge Bob");
	// patata.attack("Square Pants Sponge Bob");
	// patata.attack("Square Pants Sponge Bob");
	// patata.whoAmI();
	// patata.takeDamage(5);
	// patata.attack("Square Pants Sponge Bob");
	// patata.beRepaired(10);
	// patata.attack("Square Pants Sponge Bob");
	// patata.attack("Square Pants Sponge Bob");
	patata.whoAmI();

	return 0;
}