#include "Point.hpp"
#include <sstream>

Point::Point(): x(0), y(0)
{
}

Point::Point(float const x, float const y): x(x), y(y)
{
}

Point::~Point()
{
}

Point::Point(Point const &other): x(other.x), y(other.y)
{
}

Point &Point::operator=(Point const &other)
{
    if (this != &other)
    {
		// this->x = other.x;
		// this->y = other.y;
    }
    return *this;
}

int	Point::sign(Point const &p1, Point const &p2, Point const &p3)
{
    int	r = ((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y)).getRawBits();
	return (r > 0) - (r < 0);
}

std::string	Point::toStr() const
{
	std::stringstream s;
	s << "(" << this->x.toFloat() << "," << this->y.toFloat() << ")";
	return s.str();
}

std::ostream& operator<<(std::ostream &ost, Point const &point)
{
	ost << point.toStr();
	return ost;
}
