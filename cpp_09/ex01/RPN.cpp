#include "RPN.hpp"
#include <cctype>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;

RPN::RPN() 
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &rhs)
{
	*this = rhs;
}

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

std::string RPN::to_string() const
{
	std::stringstream	sst;
	sst << "[" << "RPN " << this << "]";
	return sst.str();
}

std::ostream &operator<<(std::ostream &ost, RPN const &rhs)
{
	ost << rhs.to_string();
	return ost;
}

template<typename T1, typename T2>
bool	is_in(T1 n, T2 min, T2 max)
{
	return min <= n && n <= max;
}
static bool	calculate_char(std::vector<int> &v, char c)
{
	if (std::isspace(c))
		return true;
	if (std::isdigit(c))
	{
		std::stringstream ss;
		ss << c;
		int	n = 0;
		ss >> n;
		v.push_back(n);
		return true;
	}
	if (v.size() < 2)
		return false;
	long	b = v.back();
	v.pop_back();
	long	a = v.back();
	v.pop_back();
	long	n = 0;
	if (c == '+')
	{
		n = a+b;
	}
	else if (c == '-')
	{
		n = a-b;
	}
	else if (c == '*')
	{
		n = a*b;
	}
	else if (c == '/')
	{
		if (b == 0)
			throw std::logic_error("division by 0");
		n = a/b;
	}
	else if (c == '%')
	{
		if (b == 0)
			throw std::logic_error("modulo by 0");
		n = a%b;
	}
	else
	{
		return false;
	}
	if (!is_in(n, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()))
		throw std::out_of_range("overflow");
	v.push_back(static_cast<int>(n));
	return true;
}

int	RPN::calculate(std::string s)
{
	std::vector<int>	v;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (!calculate_char(v, s[i]))
			throw std::logic_error("invalid experssion");
	}
	if (v.size() != 1)
		throw std::logic_error("invalid experssion");
	return v.front();
}
