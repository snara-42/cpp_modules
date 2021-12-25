#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
	static int const	k_min_grade_sign = 145;
	static int const	k_min_grade_execute = 137;

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

public:
    ShrubberyCreationForm(std::string const &target = "target");
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &rhs);

	static std::string const	name();
	virtual bool	execute(Bureaucrat const &crat) const;

};

#endif /* SHRUBBERYCREATIONFORM_HPP */
