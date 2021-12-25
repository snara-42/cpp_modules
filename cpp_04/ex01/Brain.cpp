#include "Brain.hpp"
#include <cstddef>
#include <exception>
#include <sstream>
#include <string>

Brain::Brain()
{
	std::cout << "[" << this << "] Brain constructor" << std::endl;
	for (size_t i = 0; i < this->k_n_ideas; ++i)
	{
		this->_ideas[i] = ' ' + i;
	}
}

Brain::~Brain()
{
	std::cout << "[" << this << "] Brain  destructor" << std::endl;
}

Brain::Brain(Brain const &rhs)
{
    *this = rhs;
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "[" << this << "] Brain operator= [" << &rhs << "]" << std::endl;
    if (this != &rhs)
    {
		for (size_t i = 0; i < rhs.size(); ++i)
		{
			this->_ideas[i] = rhs._ideas[i];
		}
    }
    return *this;
}

size_t	Brain::size() const
{
	return this->k_n_ideas;
}

std::string	&Brain::at(size_t n)
{
	if (this->k_n_ideas <= n)
		throw std::exception();
	return this->_ideas[n];
}

std::string	Brain::to_string() const
{
	std::stringstream s;

	s << "[";
	for (size_t i = 0; i < this->k_n_ideas; ++i)
	{
		s << this->_ideas[i];
	}
	s << "]";
	return s.str();
}

std::ostream &operator<<(std::ostream &ost, Brain const &rhs)
{
	return ost << "[" << &rhs << "] Brain " << rhs.to_string();
}
