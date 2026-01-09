#pragma once
#ifndef __CLAPTRAP__
#define __CLAPTRAP__

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#include <string>

class ClapTrap
{
private:

	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

public:
	// ? Orthodox Canonical Form
	ClapTrap(void);
	ClapTrap(ClapTrap &copy);
	ClapTrap & operator=(const ClapTrap& copy);
	~ClapTrap(void);
	// ? Orthodox Canonical Form

	ClapTrap(const std::string name);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName() const;
	int			getHitPoints() const;
	int			getEnergyPoints() const;
	int			getAttackDamage() const;
};

std::ostream & operator<<(std::ostream & o, ClapTrap const & i);

#endif // __CLAPTRAP__