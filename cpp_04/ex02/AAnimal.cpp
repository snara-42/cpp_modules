#include "AAnimal.hpp"

AAnimal::AAnimal(std::string const type): _type(type)
{
	std::cout << _type <<  " Aanimal constructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << _type <<  " Aanimal destructor" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other)
{
	std::cout << _type <<  " Aanimal copy constructor" << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(AAnimal const &other)
{
	std::cout << _type <<  " Aanimal operator=" << std::endl;
    if (this != &other)
    {
		this->_type = other._type;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, AAnimal const &rhs)
{
	ost << rhs.getType();
	return ost;
}

std::string const &	AAnimal::getType() const
{
	return this->_type;
}

void	AAnimal::makeSound() const
{
	std::cout << _type <<  " > hayim!" << std::endl;
}

