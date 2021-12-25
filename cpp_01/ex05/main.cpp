#include "Karen.hpp"
#include <iostream>

int	main()
{
	Karen	karen;

	std::cout << "DEBUG:   "; karen.complain("DEBUG");
	std::cout << "INFO:    "; karen.complain("INFO");
	std::cout << "WARNING: "; karen.complain("WARNING");
	std::cout << "ERROR:   "; karen.complain("ERROR");
	std::cout << "OTHER:   "; karen.complain("SEGV");
	return 0;
}
