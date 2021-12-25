#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string const &name): _name(name), _weapon(NULL)
{}

HumanB::~HumanB()
{}

void	HumanB::attack() const
{
	std::cout << this->_name << " attacks with " << (this->_weapon ? this->_weapon->getType() : "hand") << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
