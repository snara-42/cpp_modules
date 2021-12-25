#include "Animal.hpp"

Animal::Animal(std::string const type): _type(type)
{
	std::cout << _type <<  " animal constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << _type <<  " animal destructor" << std::endl;
}

Animal::Animal(Animal const &other)
{
	std::cout << _type <<  " animal copy constructor" << std::endl;
    *this = other;
}

Animal &Animal::operator=(Animal const &other)
{
	std::cout << _type <<  " animal operator=" << std::endl;
    if (this != &other)
    {
		this->_type = other._type;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, Animal const &rhs)
{
	ost << rhs.getType();
	return ost;
}

std::string const &	Animal::getType() const
{
	return this->_type;
}

void	Animal::makeSound() const
{
	std::cout << _type <<  " > hayim!" << std::endl;
}

