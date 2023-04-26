#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <set>
#include <queue>

class PmergeMe
{
private:
	const static size_t	N = 16;

public:
	PmergeMe();
	virtual ~PmergeMe();
	PmergeMe(PmergeMe const &rhs);
	PmergeMe &operator=(PmergeMe const &rhs);
	std::string to_string() const;

	typedef unsigned int	value_type;
	typedef value_type &	reference;
	typedef value_type *	pointer;
	typedef pointer			iterator;

	typedef	std::deque<value_type>	deque;
	typedef	std::list<value_type>	list;
	typedef	std::multiset<value_type>	multiset;
	typedef	std::priority_queue<value_type, deque, std::greater<value_type> >	priority_queue;

	static void	sort_deque(deque &c);
	static void	sort_list(list &c);
	static void	sort_multiset(multiset &c);
	static void	sort_priority_queue(priority_queue &c);

};

template<typename iterator>
iterator	prev(iterator it, ssize_t n = 1)
{
	std::advance(it, -n);
	return it;
}
template<typename iterator>
iterator	next(iterator it, ssize_t n = 1)
{
	std::advance(it, n);
	return it;
}

template<typename iterator>
std::ostream &print(iterator begin, iterator end, std::ostream &ost = std::cout);
template<typename iterator>
std::ostream &print(iterator begin, iterator end, std::ostream &ost)
{
	for (iterator it = begin; it != end; ++it)
		ost << (it != begin ? " ":"") << *it;
	ost << std::endl;
	return ost;
}

template<typename container>
std::ostream &print(const container & c, std::ostream &ost = std::cout);
template<typename container>
std::ostream &print(const container & c, std::ostream &ost)
{
	return print(c.begin(), c.end(), ost);
}

template<bool is_queue>
std::ostream &print(PmergeMe::priority_queue c, std::ostream &ost = std::cout)
{
	while (!c.empty())
		ost << c.top() << ' ', c.pop();
	ost << std::endl;
	return ost;
}

std::ostream &operator<<(std::ostream &ost, PmergeMe const &rhs);

#endif /* PMERGEME_HPP */
