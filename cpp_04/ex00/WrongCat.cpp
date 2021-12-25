#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << _type <<  " WrongCat constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << _type <<  " WrongCat destructor" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other)
{
	std::cout << _type <<  " WrongCat copy constructor" << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	std::cout << _type <<  " WrongCat operator=" << std::endl;
    if (this != &other)
    {
		this->_type = other._type;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, WrongCat const &rhs)
{
	ost << rhs.getType();
	return ost;
}

void	WrongCat::makeSound() const
{
	std::cout << _type <<  " > miaaouw!" << std::endl;
}
