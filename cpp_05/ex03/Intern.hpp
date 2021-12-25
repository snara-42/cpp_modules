#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>

class Form;

class Intern
{
private:
	static size_t const	k_n_form = 3;

public:
    Intern();
    virtual ~Intern();
    Intern(Intern const &rhs);
    Intern &operator=(Intern const &rhs);

	Form	*makeForm(std::string const &name, std::string const &target) const;
};

std::ostream &operator<<(std::ostream &ost, Intern const &rhs);

#endif /* INTERN_HPP */
