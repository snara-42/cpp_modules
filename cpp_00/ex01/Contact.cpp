#include "Contact.hpp"
#include <cstddef>
#include <sstream>
#include <iomanip>

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(Contact const &other)
{
	*this = other;
}

Contact &Contact::operator=(Contact const &other)
{
    if (this != &other)
    {
		for (size_t i = 0; i < this->size(); ++i)
			this->_info[i] = other._info[i];
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, Contact const &contact)
{
	ost << contact.print_brief();
	return ost;
}

const std::string Contact::header_at(size_t const i)
{
	const char *strs[] = {
		"first name", 
		"last name", 
		"nickname", 
		"phone number", 
		"darkest secret",
	};
	if (i >= sizeof(strs) / sizeof(strs[0]))
		throw "out of range";
	return std::string(strs[i]);
}

size_t	Contact::size() const
{
	return sizeof(this->_info) / sizeof(this->_info[0]);
}

static std::string print_info(std::string const &str, size_t len)
{
	std::stringstream	ost;

	ost << std::right;
	if (len <= 1 || str.size() <= len)
		ost << std::setw(len) << str;
	else
		ost << str.substr(0, len - 1) << '.';
	return ost.str();
}

std::string Contact::print_header()
{
	std::stringstream	ost;
	for (size_t i = 0; i <= NICKNAME; ++i)
	{
		ost << "|" << print_info(header_at(i), 10);
	}
	ost << "|" << std::endl;
	return ost.str();
}

std::string Contact::print_brief() const
{
	std::stringstream	ost;
	for (size_t i = 0; i <= NICKNAME; ++i)
	{
		ost << "|" << print_info(this->_info[i], 10);
	}
	ost << "|" << std::endl;
	return ost.str();
}

std::string Contact::print_detail() const
{
	std::stringstream	ost;
	for (size_t i = 0; i < this->size(); ++i)
	{
		ost << std::setw(16) << std::left << this->header_at(i) << ": " << this->_info[i] << std::endl;
	}
	return ost.str();
}

void Contact::add(std::istream &ist, std::ostream &ost)
{
	for (size_t i = 0; i < this->size(); ++i)
	{
		ost << std::setw(16) << std::left << this->header_at(i) << ": ";
		std::getline(ist, this->_info[i]);
	}
}

#if 0
int	main()
{
	Contact c;
	c.add(std::cin, std::cout);
	const Contact cc = c;
	std::cout << c.print_header() << c << cc;
	c.print_detail();
	return 0;
}
#endif
