#include "Phonebook.hpp"
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#ifndef PROMPT
# define PROMPT "> "
#endif
#ifndef IGNORE_CASE
# define IGNORE_CASE 0
#endif

Phonebook::Phonebook(): _i(0), _size(0)
{
	std::cout << "hi!" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "bye!" << std::endl;
}

Phonebook::Phonebook(Phonebook const &other)
{
	*this = other;
}

Phonebook &Phonebook::operator=(Phonebook const &other)
{
	if (this != &other)
	{
		this->_i = other._i;
		this->_size = other._size;
		for (size_t i = 0; i < this->_size; ++i)
		{
			this->_contact[i] = other._contact[i];
		}
	}
	return *this;
}

std::ostream &operator<<(std::ostream &ost, Phonebook const &phonebook)
{
	ost << "|" << std::right << std::setw(10) << "index" << Contact::print_header();
	ost << "---------------------------------------------" << std::endl;
	for (size_t i = 0; i < phonebook.size(); ++i)
	{
		ost << "|" << std::setw(10) << i + 1 << phonebook.at(i);
	}
	ost << "---------------------------------------------" << std::endl;
	return ost;
}

size_t	Phonebook::size() const
{
	return this->_size;
}

size_t	Phonebook::length() const
{
	return this->_size;
}

size_t	Phonebook::capacity() const
{
	return sizeof(this->_contact) / sizeof(this->_contact[0]);
}

size_t	Phonebook::next_index() const
{
	return (this->_i + 1) % this->capacity();
}

const Contact &Phonebook::at(size_t const i) const
{
	if (i >= this->size())
		throw "out of range";
	return this->_contact[i];
}

void	Phonebook::add(std::istream &ist, std::ostream &ost)
{
	this->_contact[this->_i].add(ist, ost);
	if (this->_size < this->capacity())
		this->_size += 1;
	this->_i = this->next_index();
}

static std::string	&str_toupper(std::string &str) {
	for (size_t i = 0; i < str.length(); ++i) {
		str[i] = toupper(str[i]);
	}
	return str;
}

int		Phonebook::run_cli(std::istream &cin, std::ostream &cout)
{
	cout << "welcome to awesome phonebook! what want ye to do?" << std::endl
		<< "usage: [ADD|SEARCH|EXIT]" << std::endl << PROMPT;
	for (std::string cmd=""; std::getline(cin, cmd) && !cin.eof(); cout << PROMPT)
	{
		if (IGNORE_CASE) { str_toupper(cmd);}
		if (cmd == "ADD")
		{
			cout << "fill in the following fields." << std::endl;
			this->add(cin, cout);
			cout << "done." << std::endl;
		}
		else if (cmd == "SEARCH")
		{
			if (0 == this->size())
			{
				cout << "ADD some data first!" << std::endl;
				continue;
			}
			cout << *this << std::endl << "input a number: ";
			std::getline(cin, cmd);
			std::stringstream sst(cmd);
			size_t	n = 0;
			sst >> n;
			if (sst.fail() || !(0 < n && n <= this->size()))
			{
				cout << "invalid number" << std::endl;
				continue;
			}
			cout << this->at(n - 1).print_detail();
		}
		else if (cmd == "EXIT") { break;}
		else { cout << "usage: [ADD|SEARCH|EXIT]" << std::endl;}
	}
	return 0;
}

#if 0
int	main()
{
	Phonebook p;
	std::stringstream s;
	for (size_t i = 0; i < 42; ++i) s << i<<"\n12345678901\n"<<i<<i<<"\n"<<i*11111<<"\nddddddddddd\n";
	for (size_t i = 0; i < 42; ++i) p.add(s, std::cout);
	std::cout << std::endl << p;
	const Phonebook pp = p;
	std::cout << pp << pp.at(1).print_detail();
	return 0;
}
#endif
