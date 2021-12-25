#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	{
		DiamondTrap	*p = new DiamondTrap("ponta");

		std::cout << *p << std::endl;
		p->attack("42Tokyo");
		p->takeDamage(90);
		p->takeDamage(42);
		p->beRepaired(42);
		p->guardGate();
		p->highFivesGuys();
		p->whoAmI();
		std::cout << *p << std::endl;
		std::cout << *(ScavTrap*)p << std::endl;
		std::cout << *(FragTrap*)p << std::endl;
		std::cout << *(ClapTrap*)p << std::endl;
		delete p;
	}
	std::cout << std::endl;
	{
		DiamondTrap	t;
		{
			DiamondTrap const c("adamandy");
			t = c;
		}
		std::cout << t << std::endl;
		t.attack("42Tokyo");
		t.takeDamage(90);
		t.takeDamage(42);
		t.beRepaired(42);
		t.guardGate();
		t.highFivesGuys();
		t.whoAmI();
		std::cout << t << std::endl;
	}
	return 0;
}
