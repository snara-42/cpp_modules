#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
protected:
	static const unsigned int	k_initial_hitpoint = 100;
	static const unsigned int	k_initial_energypoint = 50;
	static const unsigned int	k_initial_attack_damage = 20;

public:
    ScavTrap();
    ScavTrap(std::string const name);
    virtual ~ScavTrap();
    ScavTrap(ScavTrap const &other);
    ScavTrap &operator=(ScavTrap const &other);

	void	attack(std::string const &target);
	void	guardGate() const;
};

std::ostream &operator<<(std::ostream &ost, ScavTrap const &trap);

#endif
