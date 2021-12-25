#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
#if WRONG // compile error
	{
		AAnimal* a = new AAnimal();
		std::cout << a->getType() << " "; a->makeSound(); //will NOT output the Aanimal sound!
		delete a;
	}
#endif
	std::cout << std::endl;
	{
		AAnimal* c = new Cat();
		std::cout << *c << " "; c->makeSound(); //will output the cat sound!
		delete c;
	}
	std::cout << std::endl;
	{
		AAnimal* d = new Dog();
		std::cout << *d << " "; d->makeSound(); //will output the dog sound!
		delete d;
	}
	std::cout << std::endl;
	{
		WrongAAnimal* a = new WrongAAnimal();
		std::cout << a->getType() << " "; a->makeSound();
		delete a;
	}
	std::cout << std::endl;
	{
		WrongAAnimal* c = new WrongCat();
		std::cout << *c << " "; c->makeSound(); //will output the Aanimal sound!
		delete c;
	}
#ifdef LEAKS
	system("leaks exe");
#endif
}
