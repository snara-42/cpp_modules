#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	_name;

public:
    Zombie(std::string const &name = "anonyma");
    virtual ~Zombie();
    Zombie(Zombie const &other);
    Zombie &operator=(Zombie const &other);
	void name(std::string const &name);
	void announce(void) const;
};

Zombie	*newZombie(std::string const &name);
void	randomChump(std::string const &name);

#endif
