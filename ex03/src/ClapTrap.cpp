#include "ClapTrap.hpp"
#include <iostream>

const int C_HIT_POINTS		= 10;
const int C_ENERGY_POINTS	= 10;
const int C_ATTACK_DAMAGE	= 0;

ClapTrap::ClapTrap(std::string name, std::string type, int hitPoints, int energyPoints, int attackDamage)
: name(name), type(type), hitPoints(hitPoints), energyPoints(energyPoints), attackDamage(attackDamage)
{}

ClapTrap::ClapTrap(void) : name(__func__), type(__func__), hitPoints(C_HIT_POINTS), energyPoints(C_ENERGY_POINTS), attackDamage(C_ATTACK_DAMAGE)
{
	std::cout << GREEN << *this << __func__ << " Default constructor called\n" << RESET;
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
	std::cout << YELLOW << *this << __func__ << " Copy constructor called\n" << RESET;
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
	std::cout << CYAN << *this << __func__ << " Copy assignment operator called\n" << RESET;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED << *this << __func__ << " Destructor called\n" << RESET;
}

ClapTrap::ClapTrap(const std::string name) : name(name), type(__func__), hitPoints(C_HIT_POINTS), energyPoints(C_ENERGY_POINTS), attackDamage(C_ATTACK_DAMAGE)
{
	std::cout << GREEN << *this << __func__ << " Parametric constructor called\n" << RESET;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--this->energyPoints;
	std::cout	<< YELLOW << *this 
				<< this->type
				<< " '" << this->name
				<< "' attacks '" << target 
				<< "', causing " << this->attackDamage 
				<< " points of damage!\n" RESET;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout 	<< MAGENTA << this->type << " '" << this->name
				<< "' is receiving " << amount
				<< " points of damage!\n" RESET;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
	{
		std::cout << RED << DFLT_MSG << *this << RESET;
		return ;
	}
	--this->energyPoints;
	this->hitPoints += amount;
	std::cout 	<< CYAN << this->type << " '" << this->name
				<< "' is recovering " << amount
				<< " hit points!\n" RESET;
}

std::string ClapTrap::getName() const
{
	return this->name;
}

std::string ClapTrap::getType() const
{
	return this->type;
}

int	ClapTrap::getHitPoints() const
{
	return this->hitPoints;
}

int	ClapTrap::getEnergyPoints() const
{
	return this->energyPoints;
}

int	ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}

std::ostream & operator<<(std::ostream & o, ClapTrap const & i)
{
	o << "[type: " << i.getType() << " '" << i.getName() << "' [HP: " << i.getHitPoints() << ", EP: " << i.getEnergyPoints() << ", AD: " << i.getAttackDamage() << "]\n";
	return o;
}