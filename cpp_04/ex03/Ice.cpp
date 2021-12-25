#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(): AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(Ice const &rhs): AMateria(rhs)
{
}

Ice &Ice::operator=(Ice const &rhs)
{
	AMateria::operator=(rhs);
	return *this;
}

Ice* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/*
std::ostream &operator<<(std::ostream &ost, Ice const &rhs)
{
	ost << rhs.getType();
	return ost;
}
*/
