#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <cstddef>
#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
protected:
	static size_t const k_n_materia = 4;
	std::string	_name;
	AMateria	*_materiae[k_n_materia + 1];

public:
    Character(std::string const name = "anonyma");
    virtual ~Character();
    Character(Character const &other);
    Character &operator=(Character const &other);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

	size_t	size() const;
	virtual AMateria const *at(size_t i) const;
};

std::ostream &operator<<(std::ostream &ost, Character const &rhs);

#endif // CHARACTER_HPP
