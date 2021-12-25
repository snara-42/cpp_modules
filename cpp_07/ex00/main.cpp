#include "header.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <string>


int main( void )
{
	{
		int a = 2;
		int b = 3;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << std::endl;
	}
	{
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		std::cout << std::endl;
	}
	{
		const double a = 3.141592653589793238462643383279;
		double b = 3.14;
		std::cout << std::fixed;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap( const_cast<double&>(a), b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << std::endl;
	}
	{
		Fixed a = 3.141592653589793238462643383279f;
		Fixed b = 3.14f;
		--b;
		std::cout << std::fixed;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
