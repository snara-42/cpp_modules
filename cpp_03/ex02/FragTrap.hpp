#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
protected:
	static const unsigned int	k_initial_hitpoint = 100;
	static const unsigned int	k_initial_energypoint = 100;
	static const unsigned int	k_initial_attack_damage = 30;

public:
    FragTrap();
    FragTrap(std::string const name);
    virtual ~FragTrap();
    FragTrap(FragTrap const &other);
    FragTrap &operator=(FragTrap const &other);

	void	attack(std::string const &target);
	void	highFivesGuys() const;
};

std::ostream &operator<<(std::ostream &ost, FragTrap const &trap);

#endif
