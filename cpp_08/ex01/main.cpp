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
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp << std::endl;
	std::cout << sp.longestSpan() << " " << sp.shortestSpan() << std::endl;
	std::cout << "" << std::endl;
}

void	test_rand(size_t N)
{
	std::cout << "test_rand: " << N << std::endl;
	Span s(N);
	std::vector<int> v;
	for (size_t i = 0; i < N; ++i)
		v.push_back(std::rand());
	s.addNumber(v);
	std::cout << s << std::endl;
	//std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
}

int main()
{
	test_subject();
	std::srand(std::time(NULL));
	for (unsigned n = 1; n <= 16; ++n)
		test_rand(1 << n);
	std::cout << "" << std::endl;

	Span s(4);
	try
	{
		std::cout << s << std::endl;
		std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
	}
	catch (std::exception const & e)
	{ std::cout << e.what() << std::endl; }

	int	n[] = {std::numeric_limits<int>::min(),std::numeric_limits<int>::max(), -1,1, 42,-42};
	for (unsigned i = 0; i < 6; ++i)
	{
		try
		{
			s.addNumber(n[i]);
			std::cout << s << std::endl;
			std::cout << s.shortestSpan() << " " << s.longestSpan() << std::endl;
		}
		catch (std::exception const & e)
		{ std::cout << e.what() << std::endl; }
		//std::cout << "" << std::endl;
	}
	std::cout << s << std::endl;
}
