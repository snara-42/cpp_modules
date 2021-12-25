#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
protected:
	std::string	_type;

public:
    AAnimal(std::string const type = "AAnimal");
    virtual ~AAnimal();
    AAnimal(AAnimal const &other);
    AAnimal &operator=(AAnimal const &other);

	virtual std::string const &	getType() const;
	virtual void	makeSound() const = 0;
};

std::ostream &operator<<(std::ostream &ost, AAnimal const &rhs);

#endif // AANIMAL_HPP
