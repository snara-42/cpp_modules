#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice: virtual public AMateria
{
protected:

    Ice &operator=(Ice const &other);

public:
    Ice();
    virtual ~Ice();
    Ice(Ice const &other);

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};

std::ostream &operator<<(std::ostream &ost, Ice const &rhs);

#endif // ICE_HPP
