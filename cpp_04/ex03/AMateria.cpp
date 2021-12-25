#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

AMateria::AMateria(std::string const &type): _type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const &rhs): _type(rhs._type)
{
}

AMateria &AMateria::operator=(AMateria const &rhs)
{
    if (this != &rhs)
    {
		if (this->_type != rhs._type)
			throw std::runtime_error("cannot assign different type");
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, AMateria const &rhs)
{
	ost << "AMateria " << rhs.getType();
	return ost;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses " << this->_type << " on " << target.getName() << " *";
}
