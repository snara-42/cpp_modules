#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = n * (1 << k_point);
}

Fixed::Fixed(float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw = static_cast<int>(std::roundf(n * (1 << k_point)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
		this->_raw = other._raw;
    }
    return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(this->_raw) / (1 << k_point);
}

int		Fixed::toInt(void) const
{
	return this->_raw / (1 << k_point);
}

std::ostream &operator<<(std::ostream &ost, Fixed const &fixed)
{
	ost << fixed.toFloat();
	return ost;
}
