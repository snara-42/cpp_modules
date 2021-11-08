#include "Contact.hpp"

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
		for (size_t i = 0; i < NUM_INFO; ++i)
			this->_info[i] = other._info[i];
    }
    return *this;
}

const char *Contact::header(size_t const i)
{
	const char *strs[] = {"first_name", "last_name", "nickname", "phone_number", "darkest_secret",};
	if (i >= NUM_INFO)
		return NULL;
	return strs[i];
}

static void	print_info(std::ostream &os, std::string const &str)
{
	if (str.size() < 10)
		os << std::setw(10) << str;
	else
		os << str.substr(0,9) << ".";
}

void Contact::print_brief(std::ostream &os) const
{
	for (size_t i = 0; i <= NICKNAME; ++i)
	{
		os << "|";
		print_info(os, this->_info[i]);
	}
	os << "|";
}

std::ostream &operator<<(std::ostream &os, Contact const &contact)
{
	contact.print_brief(os);
	return os;
}

void Contact::print_detail(std::ostream &os) const
{
	for (size_t i = 0; i < NUM_INFO; ++i)
	{
		os << std::setw(16) << this->header(i) << ": " << this->_info[i] << std::endl;
	}
}
