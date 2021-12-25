#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public virtual AAnimal
{
private:
	Brain	*_brain;

public:
    Dog();
    virtual ~Dog();
    Dog(Dog const &other);
    Dog &operator=(Dog const &other);

	virtual void	makeSound() const;
	Brain*			brain() const;
};

std::ostream &operator<<(std::ostream &ost, Dog const &rhs);

#endif // DOG_HPP
