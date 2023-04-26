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

template <typename Container>
bool	t(Container& c, int n)
{
	std::cout << "[";
	for (typename Container::const_iterator it = c.begin(), ite = c.end(); it != ite; ++it)
	{ std::cout << *it << " "; }
	std::cout << "] ";
	try
	{
		std::cout << n << ": " << *easyfind(c, n) << " found!" << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
template <typename Container>
void	test()
{
	const int	N = 6;
	int	arr[N] = {0,2,4,2,0,std::numeric_limits<int>::min()};

	Container	c(arr, arr + N);
	for (int i = -1; i <= N; ++i)
	{ t(c, i); }
}

int main()
{
	std::cout << "<vector>" << std::endl;
	test< std::vector<int> >() ;

	std::cout << "<deque <const>>" << std::endl;
	test<std::deque<const int> >();

	std::cout << "<const list <const>>" << std::endl;
	test< const std::list<const int> >();

	std::cout << "<const set>" << std::endl;
	test< const std::set<int> >();

	std::cout << "<multiset>" << std::endl;
	test< std::multiset<int> >();
}
