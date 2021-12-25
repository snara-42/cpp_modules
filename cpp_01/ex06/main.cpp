#include "Karen.hpp"
#include <iostream>

int	main(int ac, char *av[])
{
	Karen	karen;

	if (ac < 2)
		karen.filter("");
	else
		karen.filter(av[1]);
	return 0;
}
