#include "FragTrap.hpp"
#include <iostream>

const int F_HIT_POINTS	= 100;
const int F_ENERGY_POINTS	= 100;
const int F_ATTACK_DAMAGE	= 30;

FragTrap::FragTrap(void) : ClapTrap(__func__, __func__, F_HIT_POINTS, F_ENERGY_POINTS, F_ATTACK_DAMAGE)
{
	this->type = __func__;
	std::cout << GREEN << *this << __func__ << " Default constructor called\n" RESET;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy)
{
	this->type = __func__;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
	}
	std::cout << YELLOW << *this << __func__ << " Copy constructor called\n" RESET;
}

ClapTrap	&FragTrap::operator=(const FragTrap& copy)
{
	this->type = __func__;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
	}
	std::cout << CYAN << *this << __func__ << " Copy assignment operator called\n" RESET;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << RED << *this << __func__ << " Destructor called\n" RESET;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, __func__, F_HIT_POINTS, F_ENERGY_POINTS, F_ATTACK_DAMAGE)
{
	std::cout << GREEN << *this << __func__ << " Parametric constructor called\n" RESET;
}

void	FragTrap::highFivesGuys()
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	std::cout << BLUE << *this << "High Five Guys!!!\n" << RESET;
}

std::ostream & operator<<(std::ostream & o, FragTrap const & i)
{
	o << "[type: " << i.getType() << " '" << i.getName() << "' HP: " << i.getHitPoints() << ", EP: " << i.getEnergyPoints() << ", AD: " << i.getAttackDamage() << "]\n";
	return o;
}