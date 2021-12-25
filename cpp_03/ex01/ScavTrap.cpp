#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap [" << _name << "] default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name)
{
	_hitpoint = ScavTrap::k_initial_hitpoint;
	_energypoint = ScavTrap::k_initial_energypoint;
	_attack_damage = ScavTrap::k_initial_attack_damage;
	std::cout << "ScavTrap [" << _name << "] constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap [" << _name << "] destructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	std::cout << "ScavTrap [" << _name << "] copy constructor" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScavTrap [" << _name << "] operator= [" << other._name << "]" << std::endl;
    if (this != &other)
    {
		this->_name = other._name;
		this->_hitpoint = other._hitpoint;
		this->_energypoint = other._energypoint;
		this->_attack_damage = other._attack_damage;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, ScavTrap const &trap)
{
	ost << "ScavTrap [" << trap.name()
		<< " (hp " << trap.hitpoint()
		<< ", ep " << trap.energypoint()
		<< ", damage " << trap.attack_damage() << ")]";
	return ost;
}

void	ScavTrap::attack(std::string const &target)
{
	this->_energypoint -= std::min(1u, this->_energypoint);
	std::cout << "ScavTrap [" << _name << "] attacks [" << target << "]"
		<< " causing (" << this->_attack_damage << ") points of damage!"
		<< " (" << this->_energypoint << ") ep left." << std::endl;
}

void	ScavTrap::guardGate() const
{
	std::cout << *this << " entered in gate keeper mode!" << std::endl;
}

/*
void	ScavTrap::takeDamage(unsigned int amount)
{
	this->_hitpoint -= std::min(amount, this->_hitpoint);
	std::cout << "ScavTrap [" << _name << "] takes (" << amount << ") hp of damage!"
		<< " (" << this->_hitpoint << ") hp left." << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	this->_hitpoint += amount;
	std::cout << "ScavTrap [" << _name << "] recovers (" << amount << ") hp!"
		<< " (" << this->_hitpoint << ") hp left." << std::endl;
}

*/
