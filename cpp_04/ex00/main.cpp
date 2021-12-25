#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* a = new Animal();
		const Animal* c = new Cat();
		const Animal* d = new Dog();
		std::cout << a->getType() << " "; a->makeSound(); //will output the animal sound!
		std::cout << c->getType() << " "; c->makeSound(); //will output the cat sound!
		std::cout << d->getType() << " "; d->makeSound(); //will output the dog sound!
		delete a;
		delete c;
		delete d;
	}
	std::cout << std::endl;
	{
		const WrongAnimal* a = new WrongAnimal();
		const WrongAnimal* c = new WrongCat();
		std::cout << a->getType() << " "; a->makeSound();
		std::cout << c->getType() << " "; c->makeSound(); //will output the animal sound!
		delete a;
		delete c;
	}
}
