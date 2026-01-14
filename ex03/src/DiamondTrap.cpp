#include "DiamondTrap.hpp"
#include <iostream>

const int D_HIT_POINTS	= 100; // ? From FragTrap
const int D_ENERGY_POINTS	= 50; // ? From ScavTrap
const int D_ATTACK_DAMAGE	= 30; // ? From FragTrap

DiamondTrap::DiamondTrap(void) : FragTrap(__func__), ScavTrap(__func__)
{
	this->name = __func__;
	this->type = __func__;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	ClapTrap::name = this->name + "_clap_name";
	std::cout << GREEN << *this << __func__ << " Default constructor called\n" RESET;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	this->type = __func__;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoints = FragTrap::hitPoints;
		this->energyPoints = ScavTrap::energyPoints;
		this->attackDamage = FragTrap::attackDamage;
	}
	std::cout << YELLOW << *this << __func__ << " Copy constructor called\n" RESET;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap& copy)
{
	this->type = __func__;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoints = FragTrap::hitPoints;
		this->energyPoints = ScavTrap::energyPoints;
		this->attackDamage = FragTrap::attackDamage;
		ClapTrap::name = copy.ClapTrap::name;
	}
	std::cout << CYAN << *this << __func__ << " Copy assignment operator called\n" RESET;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED << *this << __func__ << " Destructor called\n" RESET;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	hitPoints = D_HIT_POINTS;
	energyPoints = D_ENERGY_POINTS;
	attackDamage = D_ATTACK_DAMAGE;
	std::cout << GREEN << *this << __func__ << " Name constructor called\n" RESET;
}

// void	DiamondTrap::attack(const std::string& target)
// {
// 	if (energyPoints == 0)
// 	{
// 		std::cout << RED << DFLT_MSG << *this << RESET;
// 		return ;
// 	}
// 	--energyPoints;
// 	std::cout	<< YELLOW << *this 
// 				<< "DiamondTrap '" << name
// 				<< "' attacks " << target 
// 				<< ", causing " << attackDamage 
// 				<< " points of damage!\n" RESET;
// }

// void	DiamondTrap::takeDamage(unsigned int amount)
// {
// 	if (hitPoints == 0 || energyPoints == 0)
// 	{
// 		std::cout << RED << DFLT_MSG << *this << RESET;
// 		return ;
// 	}
// 	hitPoints -= amount;
// 	if (hitPoints < 0)
// 		hitPoints = 0;
// 	std::cout 	<< MAGENTA "DiamondTrap '" << name
// 				<< "' is receiving " << amount
// 				<< " points of damage!\n" RESET;
// }

// void	DiamondTrap::beRepaired(unsigned int amount)
// {
// 	if (hitPoints == 0 || energyPoints == 0)
// 	{
// 		std::cout << RED << DFLT_MSG << *this << RESET;
// 		return ;
// 	}
// 	--energyPoints;
// 	hitPoints += amount;
// 	std::cout 	<< CYAN "DiamondTrap '" << name
// 				<< "' is recovering " << amount
// 				<< " hit points!\n" RESET;
// }

void	DiamondTrap::whoAmI()
{
	std::cout << BLUE "I am DiamondTrap '" << name << "'\n" RESET;
	std::cout << BLUE "My ClapTrap name is '" << ClapTrap::name << "'\n" RESET;
}

std::ostream & operator<<(std::ostream & o, DiamondTrap const & i)
{
	o << "[type: " << i.getType() << " '" << i.getName() << "' HP: " << i.getHitPoints() << ", EP: " << i.getEnergyPoints() << ", AD: " << i.getAttackDamage() << "]\n";
	return o;
}