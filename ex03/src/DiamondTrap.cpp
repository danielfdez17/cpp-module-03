#include "DiamondTrap.hpp"
#include <iostream>

const int HIT_POINTS	= 100;
const int ENERGY_POINTS	= 50;
const int ATTACK_DAMAGE	= 30;
const std::string DFLT_MSG = "I cannot do anything!!!\n";

DiamondTrap::DiamondTrap(void) : FragTrap(__func__), ScavTrap(__func__)
{
	name += "_clap_name";
	FragTrap::hitPoints = HIT_POINTS;
	ScavTrap::energyPoints = ENERGY_POINTS;
	FragTrap::attackDamage = ATTACK_DAMAGE;
	std::cout << GREEN "Default constructor called\n" << *this << RESET;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) : FragTrap(copy), ScavTrap(copy)
{
	*this = copy;
	std::cout << YELLOW "Copy constructor called\n" << *this << RESET;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap& copy)
{
	this->name = copy.name;
	FragTrap::hitPoints = copy.FragTrap::hitPoints;
	ScavTrap::energyPoints = copy.ScavTrap::energyPoints;
	FragTrap::attackDamage = copy.FragTrap::attackDamage;
	std::cout << CYAN "Copy assignment operator called\n" << *this << RESET;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED "Desstructor called\n" << *this << RESET;
}

DiamondTrap::DiamondTrap(const std::string name) : FragTrap(name), ScavTrap(name)
{
	FragTrap::hitPoints = HIT_POINTS;
	ScavTrap::energyPoints = ENERGY_POINTS;
	FragTrap::attackDamage = ATTACK_DAMAGE;
	std::cout << GREEN "Name constructor called\n" << *this << RESET;
}

void	DiamondTrap::attack(const std::string& target)
{
	if (ScavTrap::energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--ScavTrap::energyPoints;
	std::cout	<< YELLOW << *this 
				<< "DiamondTrap '" << name
				<< "' attacks " << target 
				<< ", causing " << FragTrap::attackDamage 
				<< " points of damage!\n" RESET;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (FragTrap::hitPoints == 0 || ScavTrap::energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	FragTrap::hitPoints -= amount;
	if (FragTrap::hitPoints < 0)
		FragTrap::hitPoints = 0;
	std::cout 	<< MAGENTA "DiamondTrap '" << name
				<< "' is receiving " << amount
				<< " points of damage!\n" RESET;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (FragTrap::hitPoints == 0 || ScavTrap::energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--ScavTrap::energyPoints;
	FragTrap::hitPoints += amount;
	std::cout 	<< CYAN "DiamondTrap '" << name
				<< "' is recovering " << amount
				<< " hit points!\n" RESET;
}

void	DiamondTrap::guardGate()
{
	if (FragTrap::hitPoints == 0 || ScavTrap::energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	std::cout << BLUE "I am now in Gate keeper mode\n" << *this << RESET;
}

std::ostream & operator<<(std::ostream & o, DiamondTrap const & i)
{
	o << "DiamondTrap '" << i.getName() << "' [HP: " << i.getHitPoints() << ", EP: " << i.getEnergyPoints() << ", AD: " << i.getAttackDamage() << "]\n";
	return o;
}