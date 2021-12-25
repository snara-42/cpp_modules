#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const &name, Weapon &weapon): _name(name), _weapon(weapon)
{}

HumanA::~HumanA()
{}

void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with " << this->_weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}
