#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure: virtual public AMateria
{
protected:

    Cure &operator=(Cure const &other);

public:
    Cure();
    virtual ~Cure();
    Cure(Cure const &other);

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};

// std::ostream &operator<<(std::ostream &ost, Cure const &rhs);

#endif // CURE_HPP
