#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
protected:
	std::string	_type;

public:
    WrongAnimal(std::string const type = "WrongAnimal");
    virtual ~WrongAnimal();
    WrongAnimal(WrongAnimal const &other);
    WrongAnimal &operator=(WrongAnimal const &other);

	std::string const &	getType() const;
	void	makeSound() const;
};

std::ostream &operator<<(std::ostream &ost, WrongAnimal const &rhs);

#endif // WRONGANIMAL_HPP
