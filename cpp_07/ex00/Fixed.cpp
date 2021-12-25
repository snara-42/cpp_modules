#include "Fixed.hpp"
#include <cmath>
#include <exception>
#include <stdexcept>

/* structor */

Fixed::Fixed(): _raw(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_raw = n * (1 << k_point);
}

Fixed::Fixed(float n)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_raw = static_cast<int>(std::round(static_cast<double>(n) * (1 << k_point)));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	// std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/* overload */

Fixed	&Fixed::operator=(Fixed const &other)
{
	// std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
		this->_raw = other._raw;
    }
    return *this;
}

bool	Fixed::operator==(Fixed const &other) const
{
	return this->_raw == other._raw;
}
bool	Fixed::operator!=(Fixed const &other) const
{
	return this->_raw != other._raw;
}
bool	Fixed::operator>(Fixed const &other) const
{
	return this->_raw > other._raw;
}
bool	Fixed::operator>=(Fixed const &other) const
{
	return this->_raw >= other._raw;
}
bool	Fixed::operator<(Fixed const &other) const
{
	return this->_raw < other._raw;
}
bool	Fixed::operator<=(Fixed const &other) const
{
	return this->_raw <= other._raw;
}

Fixed	Fixed::operator+(Fixed const &other) const
{
	Fixed	result;
	result.setRawBits(this->_raw + other._raw);
	return result;
}
Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	result;
	result.setRawBits(this->_raw - other._raw);
	return result;
}
Fixed	Fixed::operator*(Fixed const &other) const
{
	Fixed	result(this->toFloat() * other.toFloat());
	// result.setRawBits(static_cast<long>(this->_raw * other._raw / (1 << k_point)));
	return result;
}
Fixed	Fixed::operator/(Fixed const &other) const
{
	if (other._raw == 0)
		throw std::overflow_error("division by zero");
	Fixed	result(this->toFloat() / other.toFloat());
	// result.setRawBits(static_cast<long>(this->_raw / other._raw * (1 << k_point)));
	return result;
}
Fixed	Fixed::operator%(Fixed const &other) const
{
	if (other._raw == 0)
		throw std::overflow_error("modulo by zero");
	Fixed	result;
	result.setRawBits(this->_raw % other._raw);
	// result.setRawBits(static_cast<long>(this->_raw % other._raw) * (1 << k_point));
	return result;
}

Fixed&	Fixed::operator++()
{
	++(this->_raw);
	return *this;
}
Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);
	this->operator++();
	return old;
}
Fixed&	Fixed::operator--()
{
	--(this->_raw);
	return *this;
}
Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);
	this->operator--();
	return old;
}

Fixed &Fixed::min(Fixed &fa, Fixed &fb)
{
	return fa._raw <= fb._raw ? fa : fb;
}
Fixed const &Fixed::min(Fixed const &fa, Fixed const &fb)
{
	return fa._raw <= fb._raw ? fa : fb;
}
Fixed &Fixed::max(Fixed &fa, Fixed &fb)
{
	return fa._raw >= fb._raw ? fa : fb;
}
Fixed const &Fixed::max(Fixed const &fa, Fixed const &fb)
{
	return fa._raw >= fb._raw ? fa : fb;
}

/* member function */

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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
