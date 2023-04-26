#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <functional>
#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange();
	virtual ~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &rhs);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	std::string to_string() const;

	typedef std::string	string;
	typedef std::map<string, double, std::greater<string> > map_type;
	typedef map_type::value_type pair_type;
	typedef map_type::iterator	iterator;
	typedef map_type::const_iterator	const_iterator;

	BitcoinExchange(string const &filename);
	bool				handle_file(string const &filename) const;
	static pair_type	parse_line(string const &line, char sep = ',');

private:
	map_type	map;
};

std::ostream &operator<<(std::ostream &ost, BitcoinExchange const &rhs);

#endif /* BITCOINEXCHANGE_HPP */
