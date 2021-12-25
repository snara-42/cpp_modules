#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat")
{
	std::cout << _type <<  " Cat constructor" << std::endl;
	_brain = new Brain();
}

Cat::~Cat()
{
	delete _brain;
	std::cout << _type <<  " Cat destructor" << std::endl;
}

Cat::Cat(Cat const &other)
{
	std::cout << _type <<  " Cat copy constructor" << std::endl;
	_brain = new Brain();
    *this = other;
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << _type <<  " Cat operator=" << std::endl;
    if (this != &other)
    {
		this->_type = other._type;
		if (this->_brain)
			*(this->_brain) = *(other._brain);
	}
	return *this;
}

std::ostream &operator<<(std::ostream &ost, Cat const &rhs)
{
	ost << "[" << &rhs << "] " <<  rhs.getType() << " has " << *(rhs.brain());
	return ost;
}

Brain*	Cat::brain() const
{
	return this->_brain;
}

void	Cat::makeSound() const
{
	std::cout << _type <<  " > miaaouw!" << std::endl;
}
