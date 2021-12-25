#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <string>

class Point
{
private:
	Fixed const	x;
	Fixed const	y;

public:
    Point();
    Point(float const x, float const y);
    virtual ~Point();
    Point(Point const &other);
    Point &operator=(Point const &other);
	std::string	toStr() const;
	static int	sign(Point const &p1, Point const &p2, Point const &p3);
};

std::ostream& operator<<(std::ostream &ost, Point const &point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
