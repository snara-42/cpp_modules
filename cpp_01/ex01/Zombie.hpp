#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	_name;

public:
    Zombie();
    Zombie(std::string const &name);
    virtual ~Zombie();
    Zombie(Zombie const &other);
    Zombie &operator=(Zombie const &other);
	void name(std::string const &name);
	void announce(void) const;
};

Zombie	*zombieHorde(int n, std::string const &name);

#endif
