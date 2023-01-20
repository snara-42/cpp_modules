#include "Span.hpp"
#include <cstdlib>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <algorithm>

Span::Span(unsigned n)
	:_cap(n), _shortest(std::numeric_limits<unsigned>::max()), _longest(0), _set()
{
}

Span::~Span()
{
}

Span::Span(Span const &rhs)
{
	*this = rhs;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_cap = rhs._cap;
		this->_shortest = rhs._shortest;
		this->_longest = rhs._longest;
		this->_set = rhs._set;
	}
	return *this;
}

std::string Span::to_string() const
{
	std::stringstream	sst;
	sst // << "[" << this << "] "
		<< "Span(size: " << this->_set.size()
		<< ", cap: " << this->max_size();
	(this->_set.size() >= 2
	 ? sst << ", short: " << this->shortestSpan() << ", long: " << this->longestSpan() << ")"
	 : sst << ", no span)");
	if (this->size() < 10)
	{
		sst << " [";
		for (std::multiset<int>::iterator it = _set.begin(); it != _set.end(); ++it)
			sst << " " << *it;
		sst << " ]";
	}
	return sst.str();
}

std::ostream &operator<<(std::ostream &ost, Span const &rhs)
{
	ost << rhs.to_string();
	return ost;
}

void		Span::addNumber(int val)
{
	if (_set.size() >= _cap)
		throw std::logic_error("Span: exceeded capacity limit");

	std::multiset<int>::const_iterator it = _set.lower_bound(val);
	if (it != _set.end())
	{
		unsigned	sp = static_cast<unsigned>(*it) - val;
		_shortest = std::min(_shortest, sp);
	}
	if (it != _set.begin())
	{
		unsigned	sp = static_cast<unsigned>(val) - *--it;
		_shortest = std::min(_shortest, sp);
	}
	_set.insert(val);
	it = _set.end();
	_longest = static_cast<unsigned>(*--it) - *_set.begin();
}

unsigned	Span::shortestSpan() const
{
	if (this->_set.size() < 2)
		throw std::logic_error("Span: no span");
	return this->_shortest;
}
unsigned	Span::longestSpan() const
{
	if (this->_set.size() < 2)
		throw std::logic_error("Span: no span");
	return this->_longest;
}
size_t		Span::size() const
{
	return this->_set.size();
}
size_t		Span::max_size() const
{
	return this->_cap;
}

