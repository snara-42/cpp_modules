#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <limits>
#include <string>
#include <set>

class Span
{

public:
private:
	unsigned	_cap;
	unsigned	_shortest;
	unsigned	_longest;
	std::multiset<int>	_set;

public:
	Span(unsigned n = std::numeric_limits<unsigned int>::max());
	virtual ~Span();
	Span(Span const &rhs);
	Span &operator=(Span const &rhs);
	std::string to_string() const;

	void		addNumber(int val);
	template<typename Iter>
	void		addNumber(Iter it, Iter end);
	template<typename Cont>
	void		addNumber(Cont const &c);

	unsigned	shortestSpan() const;
	unsigned	longestSpan() const;
	size_t		size() const;
	size_t		max_size() const;
};

template<typename Iter>
void		Span::addNumber(Iter it, Iter end)
{
	for (; it != end; ++it)
	{
		this->addNumber(*it);
	}
}
template<typename Cont>
void		Span::addNumber(Cont const &c)
{
	this->addNumber(c.begin(), c.end());
}

std::ostream &operator<<(std::ostream &ost, Span const &rhs);

#endif /* SPAN_HPP */
