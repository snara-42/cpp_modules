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
	public:
		GradeTooHighException(char const *message = "Form: grade too high");
	};
	class GradeTooLowException: public std::out_of_range
	{
	public:
		GradeTooLowException(char const *message = "Form: grade too low");
	};
	class WithoutSignException: public std::out_of_range
	{
	public:
		WithoutSignException(char const *message = "Form: without sign");
	};

private:
	std::string const	_name;
	bool				_is_signed;
	int					_min_grade_sign;
	int					_min_grade_execute;
	std::string const	_target;

protected:
	static int const	k_max_grade = 1;
	static int const	k_min_grade = 150;

	static void	assertGradeIsInRange(int grade);
	void		assertExecutable(Bureaucrat const &crat) const;
    Form &operator=(Form const &rhs);

public:
    Form(std::string const &name = "plain form", int const grade_sign = k_min_grade, int const grade_execute = k_min_grade, std::string const &target = "target");
    virtual ~Form();
    Form(Form const &rhs);

	std::string const &	getName() const;
	std::string const &	getTarget() const;
	int		getSignGrade() const;
	int		getExecuteGrade() const;
	bool	isSigned() const;

	virtual bool	beSigned(Bureaucrat const &crat);
	virtual bool	execute(Bureaucrat const &crat) const = 0;

};

std::ostream &operator<<(std::ostream &ost, Form const &rhs);

#endif /* FORM_HPP */
