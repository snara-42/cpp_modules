#include "Zombie.hpp"

int	main()
{
	Zombie	nameless;
	nameless.announce();

	Zombie	zeta("zeta");
	zeta.announce();

	Zombie	*ponta = newZombie("ponta");
	ponta->announce();

	randomChump("randa");

	delete ponta;
}
