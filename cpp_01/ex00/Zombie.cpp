#include "Zombie.hpp"

Zombie::Zombie(std::string const &name): _name(name)
{
	std::cout << this->_name << "\t> beeaannzZ! (constructor)" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << "\t> soooyyaaa! (destructor)" << std::endl;
}

Zombie::Zombie(Zombie const &other)
{
    *this = other;
}

Zombie &Zombie::operator=(Zombie const &other)
{
    if (this != &other)
    {
		this->_name = other._name;
    }
    return *this;
}

void Zombie::name(std::string const &name)
{
	this->_name = name;
}

void Zombie::announce(void) const
{
	std::cout << this->_name << "\t> TooooFffuuuuzzZ..." << std::endl;
}

