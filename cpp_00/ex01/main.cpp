#include "Phonebook.hpp"
#include <cstddef>
#include <sstream>
#include <string>

int	main()
{
	Phonebook	phonebook;

	return phonebook.run_cli(std::cin, std::cout);
}
