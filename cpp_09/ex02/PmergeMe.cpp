#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &rhs)
{
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

std::string PmergeMe::to_string() const
{
	std::stringstream	sst;
	sst << "[" << this << "]";
	return sst.str();
}

std::ostream &operator<<(std::ostream &ost, PmergeMe const &rhs)
{
	ost << rhs.to_string();
	return ost;
}

static void	insertion_sort(PmergeMe::list &c)
{
	typedef PmergeMe::list::iterator	iterator;
	for (iterator i = ::next(c.begin()); i != c.end(); ++i)
	{
		PmergeMe::value_type	key = *i;
		iterator	j = i;
		for (; j != c.begin() && *::prev(j) > key; --j)
		{
			std::swap(*j, *::prev(j));
		}
		// c.splice(j, c, i); // invalidates iterator
	}
}
void	PmergeMe::sort_list(list &c)
{
	typedef PmergeMe::list::iterator	iterator;
	if (c.size() < N)
	{
		insertion_sort(c);
		return;
	}
	iterator	mid = ::next(c.begin(), c.size() / 2);
	list	left, right;
	left.splice(left.begin(), c, c.begin(), mid);
	right.splice(right.begin(), c);
	sort_list(left);
	sort_list(right);
	c.merge(left);
	c.merge(right);
}


static void	insertion_sort(PmergeMe::deque &c)
{
	for (size_t i = 1; i < c.size(); ++i)
	{
		PmergeMe::value_type	key = c[i];
		size_t	j = i;
		for (; j > 0 && c[j-1] > key; --j)
		{
			std::swap(c[j], c[j-1]);
		}
	}
}
void	PmergeMe::sort_deque(deque &c)
{
	typedef PmergeMe::deque::iterator	iterator;
	if (c.size() < N)
	{
		insertion_sort(c);
		return;
	}
	iterator	mid = c.begin() + (c.size() / 2);
	deque	left, right;
	left.assign(c.begin(), mid);
	right.assign(mid, c.end());
	sort_deque(left);
	sort_deque(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), c.begin());
}

void	PmergeMe::sort_multiset(multiset &c)
{
	(void)c; // nothing to do
}

void	PmergeMe::sort_priority_queue(priority_queue &c)
{
	(void)c; // nothing to do
}
