#include "ScavTrap.hpp"
#include <iostream>

const int S_HIT_POINTS		= 100;
const int S_ENERGY_POINTS	= 50;
const int S_ATTACK_DAMAGE	= 20;

ScavTrap::ScavTrap(void) : ClapTrap(__func__, __func__, S_HIT_POINTS, S_ENERGY_POINTS, S_ATTACK_DAMAGE)
{
	this->type = __func__;
	std::cout << GREEN << *this << __func__ << " Default constructor called\n" RESET;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy)
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

ClapTrap &ScavTrap::operator=(const ScavTrap &copy)
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

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << *this << __func__ << " Destructor called\n" RESET;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, __func__, S_HIT_POINTS, S_ENERGY_POINTS, S_ATTACK_DAMAGE)
{
	std::cout << GREEN << *this << __func__ << " Parametric constructor called\n" RESET;
}


void ScavTrap::guardGate()
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return;
	}
	std::cout << BLUE << *this << "I am now in Gate keeper mode\n" RESET;
}

std::ostream &operator<<(std::ostream &o, ScavTrap const &i)
{
	o << "[type: " << i.getType() << " '" << i.getName() << "' HP: " << i.getHitPoints() << ", EP: " << i.getEnergyPoints() << ", AD: " << i.getAttackDamage() << "]\n";
	return o;
}