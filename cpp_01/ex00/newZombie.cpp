#include "Zombie.hpp"
#include <new>

Zombie *newZombie(std::string const &name)
{
	Zombie	*zp = new Zombie(name);
	return zp;
}
