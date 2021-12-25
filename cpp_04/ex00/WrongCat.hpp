#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
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
