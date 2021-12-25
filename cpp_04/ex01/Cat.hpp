#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public virtual Animal
{
private:
	Brain	*_brain;

public:
    Cat();
    virtual ~Cat();
    Cat(Cat const &other);
    Cat &operator=(Cat const &other);

	virtual void	makeSound() const;
	Brain*			brain() const;
};

std::ostream &operator<<(std::ostream &ost, Cat const &rhs);

#endif // CAT_HPP
