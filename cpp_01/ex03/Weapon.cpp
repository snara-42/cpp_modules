#include "Weapon.hpp"

Weapon::Weapon(): _type()
{}

Weapon::Weapon(std::string const &type): _type(type)
{}

Weapon::~Weapon()
{}

Weapon::Weapon(Weapon const &other)
{
    *this = other;
}

Weapon &Weapon::operator=(Weapon const &other)
{
    if (this != &other)
    {
		this->_type = other._type;
    }
    return *this;
}

const std::string&	Weapon::getType() const
{
	return this->_type;
}

void	Weapon::setType(std::string const &type)
{
	this->_type = type;
}
