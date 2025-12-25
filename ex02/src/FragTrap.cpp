#include "FragTrap.hpp"
#include <iostream>

const int HIT_POINTS	= 100;
const int ENERGY_POINTS	= 50;
const int ATTACK_DAMAGE	= 20;
const std::string DFLT_MSG = "I cannot do anything!!!\n";

FragTrap::FragTrap(void) : ClapTrap("")
{
	hitPoints = HIT_POINTS;
	energyPoints = ENERGY_POINTS;
	attackDamage = ATTACK_DAMAGE;
	std::cout << GREEN "Default constructor called\n" << *this << RESET;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << YELLOW "Copy constructor called\n" << *this << RESET;
}

ClapTrap	&FragTrap::operator=(const FragTrap& copy)
{
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	std::cout << CYAN "Copy assignment operator called\n" << *this << RESET;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << RED "Desstructor called\n" << *this << RESET;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	hitPoints = HIT_POINTS;
	energyPoints = ENERGY_POINTS;
	attackDamage = ATTACK_DAMAGE;
	std::cout << GREEN "Name constructor called\n" << *this << RESET;
}

void	FragTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--energyPoints;
	std::cout	<< YELLOW << *this 
				<< "FragTrap '" << name
				<< "' attacks " << target 
				<< ", causing " << attackDamage 
				<< " points of damage!\n" RESET;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout 	<< MAGENTA "FragTrap '" << name
				<< "' is receiving " << amount
				<< " points of damage!\n" RESET;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--energyPoints;
	hitPoints += amount;
	std::cout 	<< CYAN "FragTrap '" << name
				<< "' is recovering " << amount
				<< " hit points!\n" RESET;
}

void	FragTrap::highFivesGuys()
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	std::cout << BLUE "High Five Guys!!!\n" << *this << RESET;
}

std::ostream & operator<<(std::ostream & o, FragTrap const & i)
{
	o << "FragTrap '" << i.getName() << "' [HP: " << i.getHitPoints() << ", EP: " << i.getEnergyPoints() << ", AD: " << i.getAttackDamage() << "]\n";
	return o;
}