#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>

class Data
{
private:
	std::string	s1;
	int			n;
	std::string	s2;

public:
	Data(std::string const &str = "string");
	virtual ~Data();
	Data(Data const &rhs);
	Data &operator=(Data const &rhs);
	std::string to_string() const;
};

std::ostream &operator<<(std::ostream &ost, Data const &rhs);

uintptr_t	serialize(Data *ptr);
Data*		deserialize(uintptr_t raw);

#endif /* DATA_HPP */
