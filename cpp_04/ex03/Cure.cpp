#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(): AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(Cure const &rhs): AMateria(rhs)
{
}

Cure &Cure::operator=(Cure const &rhs)
{
	AMateria::operator=(rhs);
	return *this;
}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

/*
std::ostream &operator<<(std::ostream &ost, Cure const &rhs)
{
	ost << rhs.getType();
	return ost;
}
*/
