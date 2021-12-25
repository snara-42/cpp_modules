#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap [" << _name << "] default constructor" << std::endl;
}

FragTrap::FragTrap(std::string const name): ClapTrap(name)
{
	_hitpoint = FragTrap::k_initial_hitpoint;
	_energypoint = FragTrap::k_initial_energypoint;
	_attack_damage = FragTrap::k_initial_attack_damage;
	std::cout << "FragTrap [" << _name << "] constructor" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap [" << _name << "] destructor" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other)
{
	std::cout << "FragTrap [" << _name << "] copy constructor" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	std::cout << "FragTrap [" << _name << "] operator= [" << other._name << "]" << std::endl;
    if (this != &other)
    {
		this->_name = other._name;
		this->_hitpoint = other._hitpoint;
		this->_energypoint = other._energypoint;
		this->_attack_damage = other._attack_damage;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, FragTrap const &trap)
{
	ost << "FragTrap [" << trap.name()
		<< " (hp " << trap.hitpoint()
		<< ", ep " << trap.energypoint()
		<< ", damage " << trap.attack_damage() << ")]";
	return ost;
}

void	FragTrap::highFivesGuys() const
{
	std::cout << *this << " > high five!" << std::endl;
}

/*

void	FragTrap::attack(std::string const &target)
{
	this->_energypoint -= std::min(1u, this->_energypoint);
	std::cout << "FragTrap [" << _name << "] attacks [" << target << "]"
		<< " causing (" << this->_attack_damage << ") points of damage!"
		<< " (" << this->_energypoint << ") ep left." << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	this->_hitpoint -= std::min(amount, this->_hitpoint);
	std::cout << "FragTrap [" << _name << "] takes (" << amount << ") hp of damage!"
		<< " (" << this->_hitpoint << ") hp left." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	this->_hitpoint += amount;
	std::cout << "FragTrap [" << _name << "] recovers (" << amount << ") hp!"
		<< " (" << this->_hitpoint << ") hp left." << std::endl;
}

*/

