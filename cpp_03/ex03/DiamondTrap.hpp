#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public virtual FragTrap, public virtual ScavTrap
{
private:
	std::string	_name;

protected:
	static const unsigned int	k_initial_hitpoint = FragTrap::k_initial_hitpoint;
	static const unsigned int	k_initial_energypoint = ScavTrap::k_initial_energypoint;
	static const unsigned int	k_initial_attack_damage = FragTrap::k_initial_attack_damage;

public:
    DiamondTrap();
    DiamondTrap(std::string const name);
    virtual ~DiamondTrap();
    DiamondTrap(DiamondTrap const &other);
    DiamondTrap &operator=(DiamondTrap const &other);

	void		whoAmI() const;
	std::string	to_string() const;
};

std::ostream &operator<<(std::ostream &ost, DiamondTrap const &trap);

#endif
