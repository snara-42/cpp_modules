#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <cstddef>
#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
private:
	static size_t const k_n_materia = 4;
	AMateria	*_materiae[k_n_materia + 1];

public:
    MateriaSource();
    virtual ~MateriaSource();
    MateriaSource(MateriaSource const &other);
    MateriaSource &operator=(MateriaSource const &other);

	virtual void learnMateria(AMateria *m);
	virtual AMateria* createMateria(std::string const & type) const;

	size_t	size() const;
	virtual AMateria const *at(size_t i) const;
};

std::ostream &operator<<(std::ostream &ost, MateriaSource const &rhs);

#endif // MATERIASOURCE_HPP
