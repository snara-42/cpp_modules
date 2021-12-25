#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
	static int const	k_min_grade_sign = 72;
	static int const	k_min_grade_execute = 45;

    RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

public:
    RobotomyRequestForm(std::string const &target = "target");
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &rhs);

	static std::string const	name();
	virtual bool	execute(Bureaucrat const &crat) const;

};

#endif /* ROBOTOMYREQUESTFORM_HPP */
