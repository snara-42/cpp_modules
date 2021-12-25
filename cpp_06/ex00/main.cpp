#include "Convert.hpp"
#include <exception>
#include <iostream>
#include <sstream>
#ifndef DEBUG
# define DEBUG 0
#endif //DEBUG

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "usage: " << av[0] << " STRING" << std::endl;
		return 0;
	}

	try
	{
		Convert	conv(av[1], DEBUG);
		std::cout << conv;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
