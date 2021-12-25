#include "ClapTrap.hpp"

int	main()
{
	{
		ClapTrap	*p = new ClapTrap("ponta");

		std::cout << *p << std::endl;
		p->attack("42Tokyo");
		p->takeDamage(9);
		p->takeDamage(42);
		p->beRepaired(42);
		std::cout << *p << std::endl;
		delete p;
	}
	std::cout << std::endl;
	{
		ClapTrap	c("clappy");
		ClapTrap	t(c);

		std::cout << t << std::endl;
		t.attack("42Tokyo");
		t.takeDamage(9);
		t.takeDamage(42);
		t.beRepaired(42);
		std::cout << t << std::endl;
	}
	return 0;
}
