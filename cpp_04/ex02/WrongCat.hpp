#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAAnimal.hpp"

class WrongCat: public WrongAAnimal
{
private:

public:
    WrongCat();
    virtual ~WrongCat();
    WrongCat(WrongCat const &other);
    WrongCat &operator=(WrongCat const &other);
	void	makeSound() const;
};

#endif // WRONGCAT_HPP
