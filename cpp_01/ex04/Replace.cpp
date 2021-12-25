#include "Replace.hpp"
#include <iostream>
#include <sstream>

Replace::Replace(string const &s1, string const &s2, std::istream &cin, std::ostream &cout):
	_fname(), _s1(s1), _s2(s2), _cin(cin), _cout(cout)
{
	if (_s1.empty())
		throw "string FROM cannot be empty";
	if (!_cin)
		throw "failed to open input file";
	if (!_cout)
		throw "failed to create .replace file";
}

Replace::~Replace()
{
}

void	Replace::replace()
{
	std::stringstream	sst;
	_cin >> sst.rdbuf();
	std::string str(sst.str());

	for (size_t i = 0; i < str.size(); ++i)
	{
		size_t	j = 0;
		for (; j < _s1.size() && str[i + j] == _s1[j]; ++j)
			;
		if (j == _s1.size())
		{
			_cout << _s2;
			i += j - 1;
			continue;
		}
		else
		{
			_cout << str[i];
		}
	}
}
