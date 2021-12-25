#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria;

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) const = 0;
};

#endif // IMATERIASOURCE_HPP
