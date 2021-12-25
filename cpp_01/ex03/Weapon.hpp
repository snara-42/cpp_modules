#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
private:
	std::string _type;

public:
    Weapon();
    Weapon(std::string const &type);
    virtual ~Weapon();
    Weapon(Weapon const &other);
    Weapon &operator=(Weapon const &other);

	const std::string	&getType() const;
	void	setType(std::string const &type);
};

#endif
