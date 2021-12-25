#include "Dog.hpp"


Dog::Dog(): Animal("Dog")
{
	std::cout << _type <<  " Dog constructor" << std::endl;
	_brain = new Brain();
}

Dog::~Dog()
{
	delete _brain;
	std::cout << _type <<  " Dog destructor" << std::endl;
}

Dog::Dog(Dog const &other)
{
	std::cout << _type <<  " Dog copy constructor" << std::endl;
	_brain = new Brain();
    *this = other;
}

Dog &Dog::operator=(Dog const &other)
{
	std::cout << _type <<  " Dog operator=" << std::endl;
    if (this != &other)
    {
		this->_type = other._type;
		if (this->_brain)
			*(this->_brain) = *(other._brain);
	}
	return *this;
}

std::ostream &operator<<(std::ostream &ost, Dog const &rhs)
{
	ost << "[" << &rhs << "] " <<  rhs.getType() << " has " << *(rhs.brain());
	return ost;
}

Brain*	Dog::brain() const
{
	return this->_brain;
}

void	Dog::makeSound() const
{
	std::cout << _type <<  " > biaaown!" << std::endl;
}
