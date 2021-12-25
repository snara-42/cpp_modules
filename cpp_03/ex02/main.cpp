#include "FragTrap.hpp"

int	main()
{
	{
		FragTrap	*p = new FragTrap("ponta");

		std::cout << *p << std::endl;
		p->attack("42Tokyo");
		p->takeDamage(90);
		p->takeDamage(42);
		p->beRepaired(42);
		p->highFivesGuys();
		std::cout << *p << std::endl;
		delete p;
	}
	std::cout << std::endl;
	{
		FragTrap	t;
		{
			FragTrap const c("fraggy");
			t = c;
		}

		std::cout << t << std::endl;
		t.attack("42Tokyo");
		t.takeDamage(90);
		t.takeDamage(42);
		t.beRepaired(42);
		t.highFivesGuys();
		std::cout << t << std::endl;
	}
	return 0;
}
