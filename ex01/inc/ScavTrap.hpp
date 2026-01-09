#pragma once
#ifndef __SCAVTRAP__
#define __SCAVTRAP__

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	// ? Orthodox Canonical Form
	ScavTrap(void);
	ScavTrap(ScavTrap &copy);
	ClapTrap &operator=(const ScavTrap &copy);
	~ScavTrap(void);
	// ? Orthodox Canonical Form

	ScavTrap(const std::string name);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void guardGate();
};

std::ostream &operator<<(std::ostream &o, ScavTrap const &i);

#endif // __SCAVTRAP__