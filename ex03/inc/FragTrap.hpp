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

class FragTrap : public ClapTrap
{
public:
	// ? Orthodox Canonical Form
	FragTrap(void);
	FragTrap(FragTrap &copy);
	ClapTrap & operator=(const FragTrap& copy);
	~FragTrap(void);
	// ? Orthodox Canonical Form

	FragTrap(const std::string name);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	highFivesGuys(void);
};

std::ostream & operator<<(std::ostream & o, FragTrap const & i);

#endif // __FRAGTRAP__