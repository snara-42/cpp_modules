#include "Convert.hpp"
#include <cctype>
#include <ios>
#include <limits>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <string>

Convert::Convert(std::string const &str, bool debug): _c(0), _i(0), _f(0), _d(0), _str(str)
{
	if (_str.size() == 3 && _str[0] == '\'' && _str[2] == '\'') // char
	{
		if (debug)
			std::cout << "char\n";
		*this = _str[1];
		return;
	}
	if (_str.size() == 1 && !std::isdigit(_str[0])) // char
	{
		if (debug)
			std::cout << "char\n";
		*this = _str[0];
		return;
	}

	std::stringstream	sst(str);
	sst >> _str;
	if (sst.fail() || _str != sst.str())
		throw std::invalid_argument("invalid argument: \"" + str + "\"");

	char	*p = NULL;

	errno = 0;
	std::strtol(_str.c_str(), &p, 10);
	sst.clear();
	sst.str(_str);
	sst >> _i;
	if (sst && !errno && !p[0])
	{
		if (debug)
			std::cout << "int\n";
		*this = _i;
		return;
	}

	errno = 0;
	std::strtod(_str.c_str(), &p);
	sst.clear();
	sst.str(_str);
	sst >> _d;
	if (sst && !errno && !p[0])
	{
		if (debug)
			std::cout << "double\n";
		*this = _d;
		return;
	}

	if (_str[_str.size() - 1] == 'f')
	{
		_str[_str.size() - 1] = '\0';
		_str = _str.c_str();
		sst.str(_str);
		errno = 0;
		std::strtof(_str.c_str(), &p);
		sst.clear();
		sst >> _f;
		if (sst && !errno && !p[0])
		{
			if (debug)
				std::cout << "float\n";
			*this = _f;
			return;
		}
	}

	throw std::invalid_argument("invalid argument: \"" + str + "\"");
}

Convert::~Convert()
{
}

Convert::Convert(Convert const &rhs)
{
	*this = rhs;
}

Convert &Convert::operator=(Convert const &rhs)
{
	if (this != &rhs)
	{
		this->_str = rhs._str;
		this->_c = rhs._c;
		this->_i = rhs._i;
		this->_f = rhs._f;
		this->_d = rhs._d;
	}
	return *this;
}

std::string Convert::to_string() const
{
	std::stringstream	sst;

	sst << "char: ";
	if (_d - _d != 0 || !(std::numeric_limits<char>::min() <= _d && _d <= std::numeric_limits<char>::max()))
		sst << "impossible";
	else if (std::isprint(_c))
		sst << "'" << _c << "'";
	else
		sst << "Non displayable";
	sst << std::endl;

	sst << "int: ";
	if (_d != _d)
		sst << "impossible";
	else if (std::numeric_limits<int>::min() <= _d && _d <= std::numeric_limits<int>::max())
		sst << _i;
	else
		sst << "overflow";
	sst << std::endl;

	sst << "float: " << std::fixed;
	if (_i == _f)
		sst << std::setprecision(1);
	sst << _f << "f" << std::endl;

	sst << "double: " << std::fixed;
	if (_i == _d)
		sst << std::setprecision(1);
	sst << _d << std::endl;

	return sst.str();
}

std::ostream &operator<<(std::ostream &ost, Convert const &rhs)
{
	ost << rhs.to_string();
	return ost;
}
