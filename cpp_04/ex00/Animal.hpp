#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
protected:
	std::string	_type;

public:
    Animal(std::string const type = "Animal");
    virtual ~Animal();
    Animal(Animal const &other);
    Animal &operator=(Animal const &other);

	virtual std::string const &	getType() const;
	virtual void	makeSound() const;
};

std::ostream &operator<<(std::ostream &ost, Animal const &rhs);

#endif // ANIMAL_HPP
