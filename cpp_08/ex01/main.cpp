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
	std::cout << "test_subject: " << std::endl;
	Span sp = Span(5);
	std::cout << sp << std::endl;
	std::cout << "add(5,3,17,9,11)" << std::endl;
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp << std::endl;
	std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void	test_rand(size_t N)
{
	std::cout << "test_rand: " << N << std::endl;
	std::vector<int> v;
	for (size_t i = 0; i < N; ++i)
		v.push_back(std::rand());

	Span s(N);
	s.addNumber(v);
	std::cout << s << std::endl;
	//std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
}

void	test_mine()
{
	Span s(6);
	try
	{
		std::cout << s << std::endl;
		std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
	}
	catch (std::exception const & e)
	{ std::cout << e.what() << std::endl; }

	int	n[] = {std::numeric_limits<int>::min(),std::numeric_limits<int>::max(), 42,-42, 1,-1, 0};
	for (unsigned i = 0; i < 7; ++i)
	{
		try
		{
			std::cout << "add: " << n[i] << std::endl;
			s.addNumber(n[i]);
			std::cout << s << std::endl;
		}
		catch (std::exception const & e)
		{ std::cout << e.what() << std::endl; }
	}
	std::cout << s << std::endl;
}

int main()
{
	test_subject();

	std::srand(std::time(NULL));
	for (unsigned n = 1; n <= 16; ++n)
		test_rand(1 << n);

	std::cout << std::endl;
	test_mine();
}
