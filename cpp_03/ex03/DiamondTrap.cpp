#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <sstream>

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap [" << _name << "] default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	_hitpoint = FragTrap::k_initial_hitpoint;
	_energypoint = ScavTrap::k_initial_energypoint;
	_attack_damage = FragTrap::k_initial_attack_damage;
	std::cout << "DiamondTrap [" << _name << "] constructor" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap [" << _name << "] destructor" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
{
	std::cout << "DiamondTrap [" << _name << "] copy constructor" << std::endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "DiamondTrap [" << _name << "] operator= [" << other._name << "]" << std::endl;
    if (this != &other)
    {
		this->_name = other._name;
		this->ClapTrap::_name = other.ClapTrap::_name;
		this->_hitpoint = other._hitpoint;
		this->_energypoint = other._energypoint;
		this->_attack_damage = other._attack_damage;
    }
    return *this;
}

std::string	DiamondTrap::to_string() const
{
	std::stringstream s;

	s << "DiamondTrap [" << this->_name << "]"
		<< " aka ClapTrap [" << this->name()
		<< " (hp " << this->_hitpoint
		<< ", ep " << this->_energypoint
		<< ", damage " << this->_attack_damage << ")]";
	return s.str();
}

std::ostream &operator<<(std::ostream &ost, DiamondTrap const &trap)
{
	ost << trap.to_string();
	return ost;
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap [" << this->_name << "] aka ClapTrap [" << this->ClapTrap::_name << "]" << std::endl;
}

/*
void	DimondTrap::attack(std::string const &target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	this->_hitpoint -= std::min(amount, this->_hitpoint);
	std::cout << "DiamondTrap [" << _name << "] takes (" << amount << ") hp of damage!"
		<< " (" << this->_hitpoint << ") hp left." << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	this->_hitpoint += amount;
	std::cout << "DiamondTrap [" << _name << "] recovers (" << amount << ") hp!"
		<< " (" << this->_hitpoint << ") hp left." << std::endl;
}

*/

