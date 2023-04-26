#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		cout << "usage: " << av[0] << " input_file " << endl;
		return 0;
	}
	try
	{
		BitcoinExchange	btc("data.csv");
		btc.handle_file(av[1]);
	}
	catch (std::exception const &e)
	{
		cout << "Error: " << e.what() << endl;
	}

}
