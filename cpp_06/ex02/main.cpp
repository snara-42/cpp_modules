#include "Base.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base * generate()
{
	switch (rand() % 3)
	{
	case 0:
		std::cout << "A ";
		return new A();
	case 1:
		std::cout << "B ";
		return new B();
	case 2:
		std::cout << "C ";
		return new C();
	}
	throw std::exception();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A ";
		return;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "B ";
		return;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C ";
		return;
	}
	throw std::exception();
}

void identify(Base& p)
{
	try
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A ";
		return;
	}
	catch (std::bad_cast)
	{}
	try
	{
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "B ";
		return;
	}
	catch (std::bad_cast)
	{}
	try
	{
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "C ";
		return;
	}
	catch (std::bad_cast)
	{}
	throw std::exception();
}

int	main(int, char *av[])
{
	std::srand(reinterpret_cast<time_t>(av));
	for (int i = 0; i < 9; ++i)
	{
		try
		{
			Base *p = generate();
			std::cout << "[" << p << "]";
			std::cout << "  ptr: ";
			identify(p);
			std::cout << ", ref: ";
			identify(*p);
			std::cout << std::endl;
			delete p;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
