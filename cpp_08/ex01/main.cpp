#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <limits>
#include <vector>
#include "Span.hpp"

void	test_subject()
{
	Span sp = Span(5);
	std::cout << sp << std::endl;
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp << std::endl;
	std::cout << sp.longestSpan() << " " << sp.shortestSpan() << std::endl;
}

void	test_rand(size_t N)
{
	Span s(N);
	std::cout << s << std::endl;
	std::vector<int> v;
	for (size_t i = 0; i < N; ++i)
		v.push_back(std::rand());
	s.addNumber(v);
	std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
}

int main()
{
	test_subject();
	std::srand(std::time(NULL));
	std::cout << "" << std::endl;
	for (unsigned n = 1; n <= 16; ++n)
		test_rand(1 << n);
	std::cout << "" << std::endl;

	try
	{
		Span s(4);
		try
		{
			std::cout << s << std::endl;
			std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
		}
		catch (std::exception const & e)
		{ std::cout << e.what() << std::endl; }
		try
		{
			s.addNumber(std::numeric_limits<int>::min());
			std::cout << s << std::endl;
			std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
		}
		catch (std::exception const & e)
		{ std::cout << e.what() << std::endl; }
		try
		{
			s.addNumber(std::numeric_limits<int>::max());
			std::cout << s << std::endl;
			std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
		}
		catch (std::exception const & e)
		{ std::cout << e.what() << std::endl; }
		try
		{
			s.addNumber(0);
			std::cout << s << std::endl;
			std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
		}
		catch (std::exception const & e)
		{ std::cout << e.what() << std::endl; }
		try
		{
			s.addNumber(0);
			std::cout << s << std::endl;
			std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
		}
		catch (std::exception const & e)
		{ std::cout << e.what() << std::endl; }
		try
		{
			std::cout << s << std::endl;
			s.addNumber(42);
			std::cout << s << std::endl;
			std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
		}
		catch (std::exception const & e)
		{ std::cout << e.what() << std::endl; }
		std::cout << s << std::endl;
	}
	catch (std::exception const & e)
	{ std::cout << e.what() << std::endl; }
}
