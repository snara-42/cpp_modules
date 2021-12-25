#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
private:
	int					_raw;
	static int const	_point = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(Fixed const &other);
    Fixed &operator=(Fixed const &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
