#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <deque>

template <class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
private:

public:
	typedef typename Container::iterator		iterator;
	typedef typename Container::const_iterator	const_iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;

	MutantStack(): std::stack<T, Container>()
	{}
	virtual ~MutantStack()
	{}
	MutantStack(MutantStack const &rhs): std::stack<T, Container>(rhs)
	{}
	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
		{
			std::stack<T, Container>::operator=(rhs);
		}
		return *this;
	}

	virtual iterator		begin()
	{
		return this->c.begin();
	}
	virtual iterator		end()
	{
		return this->c.end();
	}
	virtual const_iterator	begin() const
	{
		return this->c.begin();
	}
	virtual const_iterator	end() const
	{
		return this->c.end();
	}
	virtual reverse_iterator		rbegin()
	{
		return this->c.rbegin();
	}
	virtual reverse_iterator		rend()
	{
		return this->c.rend();
	}
	virtual const_reverse_iterator	rbegin() const
	{
		return this->c.rbegin();
	}
	virtual const_reverse_iterator	rend() const
	{
		return this->c.rend();
	}

	virtual std::string to_string() const
	{
		std::stringstream	sst;
		sst // << "[" << this << "]"
			<< "MutantStack"
			<< "(" << this->size() << ") [";
		for (const_iterator it = this->begin(); it != this->end(); ++it)
			sst << *it << ",";
		sst << "]";
		return sst.str();
	}

};

template<typename T, class Container>
std::ostream &operator<<(std::ostream &ost, MutantStack<T, Container> const &rhs)
{
	ost << rhs.to_string();
	return ost;
}

#endif /* MUTANTSTACK_HPP */
