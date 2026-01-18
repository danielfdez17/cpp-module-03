#pragma once
#ifndef __FRAGTRAP__
#define __FRAGTRAP__

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string name,
	std::string type,
	int hitPoints,
	int energyPoints,
	int attackDamage);
	// ? Orthodox Canonical Form
	FragTrap(void);
	FragTrap(FragTrap &copy);
	FragTrap & operator=(const FragTrap& copy);
	~FragTrap(void);
	// ? Orthodox Canonical Form

	FragTrap(const std::string name);

	void	highFivesGuys(void);
};

std::ostream & operator<<(std::ostream & o, FragTrap const & i);

#endif // __FRAGTRAP__