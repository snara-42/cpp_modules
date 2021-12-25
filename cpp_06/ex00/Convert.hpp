#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>

class Convert
{
private:
	char		_c;
	int			_i;
	float		_f;
	double		_d;
	std::string	_str;

	Convert(Convert const &rhs);
	Convert &operator=(Convert const &rhs);

	template<typename T>
	Convert &operator=(T const rhs)
	{
		this->_c = static_cast<char>(rhs);
		this->_i = static_cast<int>(rhs);
		this->_f = static_cast<float>(rhs);
		this->_d = static_cast<double>(rhs);
		return *this;
	}

public:
	Convert(std::string const &str, bool debug = false);
	virtual ~Convert();
	std::string to_string() const;
};

std::ostream &operator<<(std::ostream &ost, Convert const &rhs);

#endif /* CONVERT_HPP */
