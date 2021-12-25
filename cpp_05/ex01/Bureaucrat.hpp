#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

class Form;

class Bureaucrat
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
	int					_grade;
	static int const	k_max_grade = 1;
	static int const	k_min_grade = 150;

	static void	assertGradeIsInRange(int grade);
    Bureaucrat &operator=(Bureaucrat const &rhs);

public:
    Bureaucrat(std::string const &name = "anonyma", int const grade = k_min_grade);
    virtual ~Bureaucrat();
    Bureaucrat(Bureaucrat const &rhs);

	void		incrementGrade();
    Bureaucrat &operator++();
    Bureaucrat	operator++(int);
	void		decrementGrade();
    Bureaucrat &operator--();
    Bureaucrat	operator--(int);

	std::string const &	getName() const;
	int		getGrade() const;
	bool	signForm(Form &form) const;

};

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &rhs);

#endif /* BUREAUCRAT_HPP */
