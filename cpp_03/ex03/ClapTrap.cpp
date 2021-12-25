#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name(), _hitpoint(k_initial_hitpoint), _energypoint(k_initial_energypoint), _attack_damage(k_initial_attack_damage)
{
	std::cout << "ClapTrap [" << _name << "] default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string const name)
	: _name(name), _hitpoint(k_initial_hitpoint), _energypoint(k_initial_energypoint), _attack_damage(k_initial_attack_damage)
{
	std::cout << "ClapTrap [" << _name << "] constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap [" << _name << "] destructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap [" << _name << "] copy constructor" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap [" << _name << "] operator= [" << other._name << "]" << std::endl;
    if (this != &other)
    {
		this->_name = other._name;
		this->_hitpoint = other._hitpoint;
		this->_energypoint = other._energypoint;
		this->_attack_damage = other._attack_damage;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, ClapTrap const &trap)
{
	ost << "ClapTrap [" << trap.name()
		<< " (hp " << trap.hitpoint()
		<< ", ep " << trap.energypoint()
		<< ", damage " << trap.attack_damage() << ")]";
	return ost;
}

std::string const &	ClapTrap::name() const
{
	return this->_name;
}
unsigned int		ClapTrap::hitpoint() const
{
	return this->_hitpoint;
}
unsigned int	ClapTrap::energypoint() const
{
	return this->_energypoint;
}
unsigned int	ClapTrap::attack_damage() const
{
	return this->_attack_damage;
}

void	ClapTrap::attack(std::string const &target)
{
	this->_energypoint -= std::min(1u, this->_energypoint);
	std::cout << "ClapTrap [" << _name << "] attacks [" << target << "]"
		<< " causing (" << this->_attack_damage << ") points of damage!"
		<< " (" << this->_energypoint << ") ep left." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitpoint -= std::min(amount, this->_hitpoint);
	std::cout << "ClapTrap [" << _name << "] takes (" << amount << ") hp of damage!"
		<< " (" << this->_hitpoint << ") hp left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitpoint += amount;
	std::cout << "ClapTrap [" << _name << "] recovers (" << amount << ") hp!"
		<< " (" << this->_hitpoint << ") hp left." << std::endl;
}

