#include "ScavTrap.hpp"

int	main()
{
	{
		ScavTrap	*p = new ScavTrap("ponta");

		std::cout << *p << std::endl;
		p->attack("42Tokyo");
		p->takeDamage(90);
		p->takeDamage(42);
		p->beRepaired(42);
		p->guardGate();
		std::cout << *p << std::endl;
		delete p;
	}
	std::cout << std::endl;
	{
		ScavTrap	t;
		{
			ScavTrap const c("scavvy");
			t = c;
		}

		std::cout << t << std::endl;
		t.attack("42Tokyo");
		t.takeDamage(90);
		t.takeDamage(42);
		t.beRepaired(42);
		t.guardGate();
		std::cout << t << std::endl;
	}
	return 0;
}
