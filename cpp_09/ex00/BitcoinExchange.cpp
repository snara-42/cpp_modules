#include "BitcoinExchange.hpp"
#include <cstddef>
#include <exception>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <utility>

using std::string;
using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs)
{
	*this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		map = rhs.map;
	}
	return *this;
}

std::string BitcoinExchange::to_string() const
{
	std::stringstream	sst;
	sst << "[" << this << "]\n";
	for (const_iterator i = map.begin(); i != map.end(); ++i)
		sst << i->first << " : " << i->second << '\n';
	return sst.str();
}

std::ostream &operator<<(std::ostream &ost, BitcoinExchange const &rhs)
{
	ost << rhs.to_string();
	return ost;
}

template<typename T>
bool	is_in(T n, T min, T max)
{
	return min <= n && n <= max;
}

static bool	is_valid_date(string const &date)
{
	const int		month_day[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
	const size_t	LEN = 10;
	const char		*dig = "0123456789";
	const string	chars[LEN] = {dig,dig,dig,dig,"-",dig,dig,"-",dig,dig};

	if (date.size() != LEN)
		return false;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (chars[i].find(date[i]) == string::npos)
			return false;
	}
	int	y, m, d;
	{
		char _;
		std::istringstream	ss(date);
		if (!(ss >> y >> _ >> m >> _ >> d))
			return false;
	}
	//TODO? leap-year 
	if (!(is_in(y, 1, 9999) && is_in(m, 1, 12) && is_in(d, 1, month_day[m])))
		return false;
	return true;
}

static string  &trim(string &s, const char *set = " \t\n\v\f\r")
{
    s.erase(0, s.find_first_not_of(set));
    s.erase(s.find_last_not_of(set)+1, string::npos);
    return s;
}
BitcoinExchange::pair_type	BitcoinExchange::parse_line(string const &line, char sep)
{
	string	date;
	double	amount;
	std::stringstream	ss(line);
	if (!std::getline(ss, date, sep) || !(ss >> amount) || !ss.eof())
		throw std::invalid_argument("invalid format");
	trim(date);
	if (!is_valid_date(date))
		throw std::invalid_argument("invalid date");
	if (amount - amount != 0 || amount < 0)
		throw std::out_of_range("invalid amount");
	return std::make_pair(date, amount);
}

BitcoinExchange::BitcoinExchange(string const &filename)
{
	std::ifstream	fs(filename);
	if (!fs)
		throw std::runtime_error("could not open database file");
	for (string line; std::getline(fs, line); )
	{
		if (line == "" || line == "date,exchange_rate")
			continue;
		try
		{
			pair_type	entry = parse_line(line, ',');
			map.insert(entry);
		}
		catch (std::exception const &e)
		{
			cout << "Error: " << e.what() << " => " << line << endl;
		}
	}
}
bool	BitcoinExchange::handle_file(std::string const &filename) const
{
	std::ifstream	fs(filename);
	if (!fs)
		throw std::runtime_error("could not open input file");
	for (string line; std::getline(fs, line); )
	{
		if (line == "" || line == "date | value")
			continue;
		try
		{
			pair_type	entry = parse_line(line, '|');
			if (!is_in(entry.second, 0.0, 1000.0))
				throw std::out_of_range("invalid amount");
			const_iterator	it = map.lower_bound(entry.first);
			if (it == map.end())
				throw std::out_of_range("no such date");
			cout << entry.first << " => " << entry.second << " = " << entry.second * it->second << endl;
		}
		catch (std::exception const &e)
		{
			cout << "Error: " << e.what() << " => " << line << endl;
		}
	}
	return true;
}
