#include "WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal(std::string const type): _type(type)
{
	std::cout << _type <<  " WrongAanimal constructor" << std::endl;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << _type <<  " WrongAanimal destructor" << std::endl;
}

WrongAAnimal::WrongAAnimal(WrongAAnimal const &other)
{
	std::cout << _type <<  " WrongAanimal copy constructor" << std::endl;
    *this = other;
}

WrongAAnimal &WrongAAnimal::operator=(WrongAAnimal const &other)
{
	std::cout << _type <<  " WrongAanimal operator=" << std::endl;
    if (this != &other)
    {
		this->_type = other._type;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, WrongAAnimal const &rhs)
{
	ost << rhs.getType();
	return ost;
}

std::string const &	WrongAAnimal::getType() const
{
	return this->_type;
}

void	WrongAAnimal::makeSound() const
{
	std::cout << _type <<  " > hayim!" << std::endl;
}
