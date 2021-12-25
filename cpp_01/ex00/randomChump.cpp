#include "Zombie.hpp"

void randomChump(std::string const &name)
{
	Zombie	z(name);

	z.announce();
}
