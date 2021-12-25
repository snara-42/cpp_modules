#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		IMateriaSource* src = new MateriaSource();
		std::cout << src << " src" << std::endl;

		try
		{
			AMateria *m = new Ice();
			std::cout << m << *m << std::endl;
			src->learnMateria(m);
			delete m;
			m = new Cure();
			std::cout << m << *m << std::endl;
			src->learnMateria(m);
			delete m;
		}
		catch (std::exception const &e)
		{
			std::cerr << e.what() << std::endl;
		}

		ICharacter* nop = new Character("nop");
		ICharacter* louis = new Character("louis");
		try
		{
			std::cout << nop << nop->getName() << std::endl;
			std::cout << louis << louis->getName() << std::endl;
			AMateria* tmp;
			tmp = src->createMateria("ice");
			std::cout << tmp << tmp->getType() << std::endl;
			nop->equip(tmp);
			tmp = src->createMateria("cure");
			std::cout << tmp << tmp->getType() << std::endl;
			nop->equip(tmp);
			nop->use(0, *louis);
			nop->use(1, *louis);
		}
		catch (std::exception const &e)
		{
			std::cerr << e.what() << std::endl;
		}
		{
			Character c("sn");
			std::cout << c << std::endl;
			MateriaSource s;
			std::cout << s << std::endl;
		}

		delete louis;
		delete nop;
		delete src;
		return 0;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
