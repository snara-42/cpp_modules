#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
	std::string _name;
	Weapon 		*_weapon;

public:
    HumanB(std::string const &name);
    virtual ~HumanB();

	void	attack() const;
	void	setWeapon(Weapon &weapon);
};

#endif
