#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public virtual Animal
{
private:

public:
    Dog();
    virtual ~Dog();
    Dog(Dog const &other);
    Dog &operator=(Dog const &other);

	virtual void	makeSound() const;
};

#endif // DOG_HPP
