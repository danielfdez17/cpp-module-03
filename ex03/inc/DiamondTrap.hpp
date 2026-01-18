#pragma once
#ifndef __DIAMONDTRAP__
#define __DIAMONDTRAP__

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	// ? Orthodox Canonical Form
	DiamondTrap(void);
	DiamondTrap(DiamondTrap &copy);
	DiamondTrap& operator=(const DiamondTrap& copy);
	~DiamondTrap(void);
	// ? Orthodox Canonical Form

	DiamondTrap(const std::string name);

	// void	attack(const std::string& target);
	// void	takeDamage(unsigned int amount);
	// void	beRepaired(unsigned int amount);

	void	whoAmI();
	std::string	getType() const;
};

std::ostream & operator<<(std::ostream & o, DiamondTrap const & i);

#endif // __DIAMONDTRAP__