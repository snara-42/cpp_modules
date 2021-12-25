#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <cstddef>
# include <iostream>
# include <string>

class Brain
{
protected:
	static size_t const	k_n_ideas = 100;
	std::string	_ideas[k_n_ideas];

public:
    Brain();
    virtual ~Brain();
    Brain(Brain const &other);
    Brain &operator=(Brain const &other);

	size_t	size() const;
	std::string	&at(size_t n);
	std::string	to_string() const;
};

std::ostream &operator<<(std::ostream &ost, Brain const &rhs);

#endif // BRAIN_HPP
