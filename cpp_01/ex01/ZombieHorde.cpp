#include "Zombie.hpp"
#include <new>

Zombie* zombieHorde(int n, std::string const &name)
{
	if (n < 0)
		throw std::bad_alloc();

	Zombie	*zp = new Zombie[n];
	for (int i = 0; i < n; ++i)
	{
		zp[i].name(name);
	}
	return zp;
}
