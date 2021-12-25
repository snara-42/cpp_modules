#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	return ((Point::sign(point, a, b) < 0 && Point::sign(point, b, c) < 0 && Point::sign(point, c, a) < 0)
			|| (Point::sign(point, a, b) > 0 && Point::sign(point, b, c) > 0 && Point::sign(point, c, a) > 0));
}
