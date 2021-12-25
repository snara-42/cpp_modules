#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_raw;
	static int const	k_point = 8;

public:
	Fixed();
	Fixed(int n);
	Fixed(float n);
	~Fixed();
	Fixed(Fixed const &other);
	Fixed&	operator=(Fixed const &other);

	bool	operator==(Fixed const &other) const;
	bool	operator!=(Fixed const &other) const;
	bool	operator>(Fixed const &other) const;
	bool	operator>=(Fixed const &other) const;
	bool	operator<(Fixed const &other) const;
	bool	operator<=(Fixed const &other) const;

	Fixed	operator+(Fixed const &other) const;
	Fixed	operator-(Fixed const &other) const;
	Fixed	operator*(Fixed const &other) const;
	Fixed	operator/(Fixed const &other) const;
	Fixed	operator%(Fixed const &other) const;
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed &min(Fixed &fa, Fixed &fb);
	static Fixed const &min(Fixed const &fa, Fixed const &fb);
	static Fixed &max(Fixed &fa, Fixed &fb);
	static Fixed const &max(Fixed const &fa, Fixed const &fb);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &ost, Fixed const &fixed);

#endif
