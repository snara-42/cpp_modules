#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hitpoint;
	unsigned int	_energypoint;
	unsigned int	_attack_damage;

	static const unsigned int	k_initial_hitpoint = 10;
	static const unsigned int	k_initial_energypoint = 10;
	static const unsigned int	k_initial_attack_damage = 0;

public:
    ClapTrap();
    ClapTrap(std::string const name);
    virtual ~ClapTrap();
    ClapTrap(ClapTrap const &other);
    ClapTrap &operator=(ClapTrap const &other);

	std::string const	&name() const;
	unsigned int		hitpoint() const;
	unsigned int		energypoint() const;
	unsigned int		attack_damage() const;
	
	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &ost, ClapTrap const &trap);

#endif
