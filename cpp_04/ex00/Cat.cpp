#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << _type <<  " Cat constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << _type <<  " Cat destructor" << std::endl;
}

Cat::Cat(Cat const &other)
{
	std::cout << _type <<  " Cat copy constructor" << std::endl;
    *this = other;
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << _type <<  " Cat operator=" << std::endl;
    if (this != &other)
    {
		this->_type = other._type;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, Cat const &rhs)
{
	ost << rhs.getType();
	return ost;
}

void	Cat::makeSound() const
{
	std::cout << _type <<  " > miaaouw!" << std::endl;
}
