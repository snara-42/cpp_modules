#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>

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

public:
    Bureaucrat(std::string const &name = "anonyma", int grade = k_min_grade);
    virtual ~Bureaucrat();
    Bureaucrat(Bureaucrat const &rhs);
    Bureaucrat &operator=(Bureaucrat const &rhs);

	void		incrementGrade();
    Bureaucrat &operator++();
    Bureaucrat	operator++(int);
	void		decrementGrade();
    Bureaucrat &operator--();
    Bureaucrat	operator--(int);

	std::string const &	getName() const;
	int					getGrade() const;

private:
	static void	assertGradeIsInRange(int grade);
};

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &rhs);

#endif /* BUREAUCRAT_HPP */
