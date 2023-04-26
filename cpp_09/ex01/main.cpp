#include "RPN.hpp"
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;
	try
	{
		cout << RPN::calculate(argv[1]) << endl;
	}
	catch (const std::exception & e)
	{
		cout << "Error: " << e.what() << endl;
	}
}
