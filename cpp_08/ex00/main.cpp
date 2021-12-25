#include <algorithm>
#include <climits>
#include <exception>
#include <limits>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include "easyfind.hpp"

template<typename Container>
bool	test(Container& c, int n)
{
	std::cout << "[";
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
	{ std::cout << *it << ", "; }
	std::cout << "] ";
	try
	{
		std::cout << n << ": ";
		typename Container::const_iterator	it = easyfind(c, n);
		std::cout << *it << " found!" << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

int main()
{
	try
	{
		const size_t	N = 6;
		int	arr[N] = {0,2,4,2,0,std::numeric_limits<int>::min()};
		{
			std::cout << "<vector>" << std::endl;
			std::vector<int> c(arr, arr + N);
			for (int i = -1; i <= static_cast<int>(N); ++i)
			{ test(c, i); }
		}
		{
			std::cout << "<const deque>" << std::endl;
			std::deque<int> const c(arr, arr + N);
			for (int i = -1; i <= static_cast<int>(N); ++i)
			{ test(c, i); }
		}
		{
			std::cout << "<list>" << std::endl;
			std::list<int> c(arr, arr + N);
			for (int i = -1; i <= static_cast<int>(N); ++i)
			{ test(c, i); }
		}
		{
			std::cout << "<const set>" << std::endl;
			std::set<int> const c(arr, arr + N);
			for (int i = -1; i <= static_cast<int>(N); ++i)
			{ test(c, i); }
		}
		{
			std::cout << "<multiset>" << std::endl;
			std::multiset<int> c(arr, arr + N);
			for (int i = -1; i <= static_cast<int>(N); ++i)
			{ test(c, i); }
		}
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
}
