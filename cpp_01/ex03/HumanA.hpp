#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
	std::string	_name;
	Weapon		&_weapon;

public:
    HumanA(std::string const &name, Weapon &weapon);
    virtual ~HumanA();

	void	attack() const;
	void	setWeapon(Weapon &weapon);
};

#endif
