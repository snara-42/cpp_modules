#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

class Bureaucrat;

class Form
{
public:
	class GradeTooHighException: public std::out_of_range
	{
	public: GradeTooHighException(char const *message = "grade too high");
	};
	class GradeTooLowException: public std::out_of_range
	{
	public: GradeTooLowException(char const *message = "grade too low");
	};

private:
	std::string const	_name;
	bool				_is_signed;
	int					_min_grade_sign;
	int					_min_grade_execute;
	static int const	k_max_grade = 1;
	static int const	k_min_grade = 150;

	static void	assertGradeIsInRange(int grade);
    Form &operator=(Form const &rhs);

public:
    Form(std::string const &name = "plain form", int const grade_sign = k_min_grade, int const grade_execute = k_min_grade);
    virtual ~Form();
    Form(Form const &rhs);

	std::string const &	getName() const;
	int		getSignGrade() const;
	int		getExecuteGrade() const;
	bool	isSigned() const;
	bool	beSigned(Bureaucrat const &crat);

};

std::ostream &operator<<(std::ostream &ost, Form const &rhs);

#endif /* FORM_HPP */
