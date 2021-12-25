#ifndef WRONGAANIMAL_HPP
# define WRONGAANIMAL_HPP

# include <iostream>
# include <string>

class WrongAAnimal
{
protected:
	std::string	_type;

public:
    WrongAAnimal(std::string const type = "WrongAAnimal");
    virtual ~WrongAAnimal();
    WrongAAnimal(WrongAAnimal const &other);
    WrongAAnimal &operator=(WrongAAnimal const &other);

	std::string const &	getType() const;
	void	makeSound() const;
};

std::ostream &operator<<(std::ostream &ost, WrongAAnimal const &rhs);

#endif // WRONGAANIMAL_HPP
