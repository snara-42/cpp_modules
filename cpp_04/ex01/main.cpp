#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstddef>

int main()
{
	{
		const size_t N = 8;
		Animal	*a[N];
		for (size_t i = 0; i < N; ++i)
		{
			if (i % 2)
				a[i] = new Dog();
			else
				a[i] = new Cat();
		}
		for (size_t i = 0; i < N; ++i)
		{
			std::cout << a[i] << " "; a[i]->makeSound();
		}
		for (size_t i = 0; i < N; ++i)
		{
			delete a[i];
		}
	}
	std::cout << std::endl;
	{
		Cat	c;
		Cat	cp(c);
		std::cout << c << std::endl;
		std::cout << cp << std::endl;
		c.brain()->at(0) = "space";
		c.brain()->at(42 - ' ') = " *the answer to everything* ";
		c.brain()->at('`' - ' ') = "^/` ";
		cp = c;
		std::cout << c << std::endl;
		std::cout << cp << std::endl;

	}
	std::cout << std::endl;
#ifdef LEAKS
	system("leaks exe");
#endif
}
