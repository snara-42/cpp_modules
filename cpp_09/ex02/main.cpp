#include "PmergeMe.hpp"
#include "Timer.hpp"
#include <algorithm>
#include <ctime>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <cstddef>
#include <unistd.h>

using std::cout;
using std::endl;
using std::string;

static unsigned int	atou(const char *s)
{
	unsigned int	n;
	std::stringstream	ss(s);
	if (!(ss.str().find_first_not_of("0123456789") == string::npos && (ss >> n) && ss.eof()))
	{
		cout << "Error:" << ss.str() << endl;
		exit(0);
	}
	return n;
}

int	main(int ac, char *av[])
{
	if (ac <= 1)
	{
		cout << "usage: " << av[0] << " numbers..." << endl;
		return 0;
	}
	const int	N = 21;
	typedef PmergeMe::value_type	value_type;
	value_type	*arr = new value_type[ac-1]();
	PmergeMe::iterator	begin = &arr[0], end = &arr[ac-1];

	std::transform(&av[1], &av[ac], begin, atou);
	if (ac <= N)
		cout << "Before: ", print(begin, end);

	{
		PmergeMe::deque	c;
		Timer	t("Time to process a range of " + std::to_string(std::distance(begin, end)) + " elements with ""std::deque"" : ");
		c.assign(begin, end);
		PmergeMe::sort_deque(c);
		t.stop();
		if (ac <= N)
			cout << "After : ", print(c);
		cout << t << endl;
	}
	{
		PmergeMe::list	c;
		Timer	t("Time to process a range of " + std::to_string(std::distance(begin, end)) + " elements with ""std::list"" : ");
		c.assign(begin, end);
		PmergeMe::sort_list(c);
		t.stop();
		if (ac <= N)
			cout << "After : ", print(c);
		cout << t << endl;
	}
	{
		PmergeMe::multiset	c;
		Timer	t("Time to process a range of " + std::to_string(std::distance(begin, end)) + " elements with ""std::multiset"" : ");
		c.insert(begin, end);
		PmergeMe::sort_multiset(c);
		t.stop();
		if (ac <= N)
			cout << "After : ", print(c);
		cout << t << endl;
	}
	{
		PmergeMe::priority_queue	c;
		Timer	t("Time to process a range of " + std::to_string(std::distance(begin, end)) + " elements with ""std::priority_queue"" : ");
		c = PmergeMe::priority_queue(begin, end);
		PmergeMe::sort_priority_queue(c);
		t.stop();
		if (ac <= N)
			cout << "After : ", print<true>(c);
		cout << t << endl;
	}
	delete[] arr;
}
