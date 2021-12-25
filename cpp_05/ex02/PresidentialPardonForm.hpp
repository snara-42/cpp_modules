#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	static int const	k_min_grade_sign = 25;
	static int const	k_min_grade_execute = 5;

    PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

public:
    PresidentialPardonForm(std::string const &target = "target");
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &rhs);

	static std::string const	name();
	virtual bool	execute(Bureaucrat const &crat) const;

};

#endif /* PRESIDENTIALPARDONFORM_HPP */
