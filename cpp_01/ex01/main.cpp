#include "Zombie.hpp"
#include <new>

int	main()
{
	int const	n = 6;
	try {
		Zombie	*cluster = zombieHorde(n, "zeta");

		for (int i = 0; i < n; ++i)
		{
			cluster[i].announce();
		}
		delete [] cluster;
	}
	catch (std::bad_alloc const &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
