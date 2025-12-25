#include "ScavTrap.hpp"
#include <iostream>

const int HIT_POINTS	= 100;
const int ENERGY_POINTS	= 50;
const int ATTACK_DAMAGE	= 20;
const std::string DFLT_MSG = "I cannot do anything!!!\n";

ScavTrap::ScavTrap(void) : ClapTrap("")
{
	std::cout << GREEN "Default constructor called\n" << *this << RESET;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << YELLOW "Copy constructor called\n" << *this << RESET;
}

ClapTrap	&ScavTrap::operator=(const ScavTrap& copy)
{
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	std::cout << CYAN "Copy assignment operator called\n" << *this << RESET;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED "Desstructor called\n" << *this << RESET;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << GREEN "Name constructor called\n" << *this << RESET;
}

void	ScavTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--energyPoints;
	std::cout	<< YELLOW << *this 
				<< "ScavTrap '" << name
				<< "' attacks " << target 
				<< ", causing " << attackDamage 
				<< " points of damage!\n" RESET;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout 	<< MAGENTA "ScavTrap '" << name
				<< "' is receiving " << amount
				<< " points of damage!\n" RESET;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--energyPoints;
	hitPoints += amount;
	std::cout 	<< CYAN "ScavTrap '" << name
				<< "' is recovering " << amount
				<< " hit points!\n" RESET;
}

void	ScavTrap::guardGate()
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	std::cout << BLUE "I am now in Gate keeper mode\n" << *this << RESET;
}

std::ostream & operator<<(std::ostream & o, ScavTrap const & i)
{
	o << "ScavTrap '" << i.getName() << "' [HP: " << i.getHitPoints() << ", EP: " << i.getEnergyPoints() << ", AD: " << i.getAttackDamage() << "]\n";
	return o;
}