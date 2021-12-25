#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << _type <<  " Dog constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << _type <<  " Dog destructor" << std::endl;
}

Dog::Dog(Dog const &other)
{
	std::cout << _type <<  " Dog copy constructor" << std::endl;
    *this = other;
}

Dog &Dog::operator=(Dog const &other)
{
	std::cout << _type <<  " Dog operator=" << std::endl;
    if (this != &other)
    {
		this->_type = other._type;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, Dog const &rhs)
{
	ost << rhs.getType();
	return ost;
}

void	Dog::makeSound() const
{
	std::cout << _type <<  " > biaaown!" << std::endl;
}
