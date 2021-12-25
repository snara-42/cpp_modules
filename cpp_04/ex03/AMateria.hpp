#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	_type;

    AMateria &operator=(AMateria const &other);

public:
    AMateria(std::string const & type = "materia");
    virtual ~AMateria();
    AMateria(AMateria const &other);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

std::ostream &operator<<(std::ostream &ost, AMateria const &rhs);

#endif // AMATERIA_HPP
