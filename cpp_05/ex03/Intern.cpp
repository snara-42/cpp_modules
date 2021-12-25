#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <iostream>

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern const &rhs)
{
    *this = rhs;
}

Intern &Intern::operator=(Intern const &rhs)
{
    if (this != &rhs)
    {
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ost, Intern const &rhs)
{
	(void)rhs;
	return ost << "intern";
}

Form	*Intern::makeForm(std::string const &name, std::string const &target) const
{
	Form	*form = NULL;
	size_t i = 0;
	std::string	form_list[] = {
		PresidentialPardonForm::name(),
		RobotomyRequestForm::name(),
		ShrubberyCreationForm::name()
	};
	for (; i < k_n_form && form_list[i] != name; ++i)
		;
	switch (i) {
		case 0:
			form = new PresidentialPardonForm(target); break;
		case 1:
			form = new RobotomyRequestForm(target); break;
		case 2:
			form = new ShrubberyCreationForm(target); break;
		default:
			std::cout << "intern couldn't find [" << name << "]..." << std::endl;
			return NULL;
	}
	std::cout << "an intern created " << *form << std::endl;
	return form;
}
