#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>

	using std::string;
class Replace
{
private:
	string	_fname;
	string	_s1;
	string	_s2;
	std::istream	&_cin;
	std::ostream	&_cout;

public:
    Replace(string const &s1, string const &s2, std::istream &cin, std::ostream &cout);
    virtual ~Replace();

	void	replace();
};

#endif
