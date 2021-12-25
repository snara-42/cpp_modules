#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string const type): _type(type)
{
	std::cout << _type <<  " Wronganimal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << _type <<  " Wronganimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << _type <<  " Wronganimal copy constructor" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << _type <<  " Wronganimal operator=" << std::endl;
    if (this != &other)
    {
		this->_type = other._type;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, WrongAnimal const &rhs)
{
	ost << rhs.getType();
	return ost;
}

std::string const &	WrongAnimal::getType() const
{
	return this->_type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << _type <<  " > hayim!" << std::endl;
}
