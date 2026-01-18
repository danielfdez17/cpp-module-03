#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap patata("patata");
	std::cout << "hit points: " << patata.getHitPoints() << " (should be 100)\n";
	std::cout << "energy points: " << patata.getEnergyPoints() << " (should be 50)\n";
	std::cout << "attack damage: " << patata.getAttackDamage() << " (should be 30)\n";
	patata.attack("Square Pants Sponge Bob");
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