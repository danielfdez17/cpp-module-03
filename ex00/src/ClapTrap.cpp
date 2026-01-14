#include "ClapTrap.hpp"
#include <iostream>

const int C_HIT_POINTS		= 10;
const int C_ENERGY_POINTS	= 10;
const int C_ATTACK_DAMAGE	= 0;
const std::string DFLT_MSG = "I can do nothing!!!\n";

ClapTrap::ClapTrap(void) : name(__func__), type(__func__), hitPoints(C_HIT_POINTS), energyPoints(C_ENERGY_POINTS), attackDamage(C_ATTACK_DAMAGE)
{
	std::cout << GREEN "Default constructor called\n" << *this << RESET;
}

ClapTrap::ClapTrap(ClapTrap &copy) : type(__func__)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->type = copy.type;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
	}
	std::cout << YELLOW "Copy constructor called\n" << *this << RESET;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->type = copy.type;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
	}
	std::cout << CYAN "Copy assignment operator called\n" << *this << RESET;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED "Desstructor called\n" << *this << RESET;
}

ClapTrap::ClapTrap(const std::string name) : name(name), type(__func__), hitPoints(C_HIT_POINTS), energyPoints(C_ENERGY_POINTS), attackDamage(C_ATTACK_DAMAGE)
{
	std::cout << GREEN "Parametric constructor called\n" << *this << RESET;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--energyPoints;
	std::cout	<< YELLOW << *this 
				<< type
				<< " '" << name
				<< "' attacks '" << target 
				<< "', causing " << attackDamage 
				<< " points of damage!\n" RESET;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout 	<< MAGENTA "ClapTrap '" << name
				<< "' is receiving " << amount
				<< " points of damage!\n" RESET;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--energyPoints;
	hitPoints += amount;
	std::cout 	<< CYAN "ClapTrap '" << name
				<< "' is recovering " << amount
				<< " hit points!\n" RESET;
}

std::string ClapTrap::getName() const
{
	return name;
}

std::string ClapTrap::getType() const
{
	return type;
}

int	ClapTrap::getHitPoints() const
{
	return hitPoints;
}

int	ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

int	ClapTrap::getAttackDamage() const
{
	return attackDamage;
}

std::ostream & operator<<(std::ostream & o, ClapTrap const & i)
{
	o << i.getType() << " '" << i.getName() << "' [HP: " << i.getHitPoints() << ", EP: " << i.getEnergyPoints() << ", AD: " << i.getAttackDamage() << "]\n";
	return o;
}