#include "Data.hpp"
#include <cstddef>
#include <exception>
#include <iostream>
#include <cstdint>
#include <string>

int	main(int ac, char **av)
{
	std::srand(reinterpret_cast<time_t>(av));
	try
	{
		Data	d(av[ac - 1]);
		std::cout << &d << " " << d << std::endl;

		uintptr_t	raw = serialize(&d);
		Data	*ptr = deserialize(raw);
		
		std::cout << ptr << " " << *ptr << std::endl << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
}

