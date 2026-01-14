#include "DiamondTrap.hpp"
#include <iostream>

const int HIT_POINTS	= 100;
const int ENERGY_POINTS	= 50;
const int ATTACK_DAMAGE	= 30;
const std::string DFLT_MSG = "I cannot do anything!!!\n";

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), FragTrap(), ScavTrap()
{
	name += "_clap_name";
	hitPoints = HIT_POINTS;
	energyPoints = ENERGY_POINTS;
	attackDamage = ATTACK_DAMAGE;
	std::cout << GREEN "Default constructor called\n" << *this << RESET;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	*this = copy;
	std::cout << YELLOW "Copy constructor called\n" << *this << RESET;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap& copy)
{
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	ClapTrap::name = copy.ClapTrap::name;
	std::cout << CYAN "Copy assignment operator called\n" << *this << RESET;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED "Destructor called\n" << *this << RESET;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	hitPoints = HIT_POINTS;
	energyPoints = ENERGY_POINTS;
	attackDamage = ATTACK_DAMAGE;
	std::cout << GREEN "Name constructor called\n" << *this << RESET;
}

void	DiamondTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--energyPoints;
	std::cout	<< YELLOW << *this 
				<< "DiamondTrap '" << name
				<< "' attacks " << target 
				<< ", causing " << attackDamage 
				<< " points of damage!\n" RESET;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout 	<< MAGENTA "DiamondTrap '" << name
				<< "' is receiving " << amount
				<< " points of damage!\n" RESET;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--energyPoints;
	hitPoints += amount;
	std::cout 	<< CYAN "DiamondTrap '" << name
				<< "' is recovering " << amount
				<< " hit points!\n" RESET;
}

void	DiamondTrap::whoAmI()
{
	std::cout << BLUE "I am DiamondTrap '" << name << "'\n" RESET;
	std::cout << BLUE "My ClapTrap name is '" << ClapTrap::name << "'\n" RESET;
}

std::ostream & operator<<(std::ostream & o, DiamondTrap const & i)
{
	o << "DiamondTrap '" << i.getName() << "' [HP: " << i.getHitPoints() << ", EP: " << i.getEnergyPoints() << ", AD: " << i.getAttackDamage() << "]\n";
	return o;
}