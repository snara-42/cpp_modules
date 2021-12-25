#include <exception>
#include <iomanip>
#include <iostream>
#include <string>

#include "Point.hpp"

void test(std::string info, const Point a, const Point b, const Point c, const Point p) {
	std::cout << std::fixed;
	std::cout // std::setw(15) 
		<< info << " : "<<p<<" in " <<a<<b<<c << (bsp(a,b,c,p) ? "\ttrue " : "\tfalse ")
		<< Point::sign(p,a,b) << Point::sign(p,b,c) << Point::sign(p,c,a) <<  std::endl;
}

int main(void) {
	Point p;
	test("...", Point(), Point(), Point(), p);
	test("|._\\", Point(0,1), Point(0,0), Point(1,0), p);
	test("/_._\\", Point(0,1), Point(-1,0), Point(1,0), p);
	test(".\\|", Point(0,1), Point(1,1), Point(1,0), p);
	test(".//", Point(-1,-1), Point(1,1), Point(1,0), p);

	test("\\./", Point(1,1), Point(0,-1), Point(-1,1), p);
	test("<.|", Point(1,1), Point(-1,0), Point(1,-1), p);
	test("|.>", Point(-0.125f,-0.125f), Point(0.125f,-0.125f), Point(0,0.125f), p);
	test("/./", Point(-4242,-1), Point(0,1), Point(4242,0), p);
	return 0;
}

