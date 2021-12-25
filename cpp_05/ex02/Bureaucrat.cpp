#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(char const *message): std::out_of_range(message) {}
Bureaucrat::GradeTooLowException::GradeTooLowException(char const *message): std::out_of_range(message) {}

void	Bureaucrat::assertGradeIsInRange(int grade)
{
	if (grade < k_max_grade)
	{
		throw GradeTooHighException();
	}
	if (grade > k_min_grade)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name), _grade(grade)
{
	assertGradeIsInRange(_grade);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
{
    *this = rhs;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	assertGradeIsInRange(rhs._grade);
    if (this != &rhs)
    {
		// const_cast<std::string&>(this->_name) = rhs._name;
		this->_grade = rhs._grade;
    }
    return *this;
}

void		Bureaucrat::incrementGrade()
{
	assertGradeIsInRange(_grade - 1);
	this->_grade -= 1;
}
Bureaucrat &Bureaucrat::operator++()
{
	incrementGrade();
	return *this;
}
Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat	old(*this);
	incrementGrade();
	return old;
}

void		Bureaucrat::decrementGrade()
{
	assertGradeIsInRange(_grade + 1);
	this->_grade += 1;
}
Bureaucrat &Bureaucrat::operator--()
{
	decrementGrade();
	return *this;
}
Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat	old(*this);
	decrementGrade();
	return old;
}


std::string const &	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

bool	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signs  " << form << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << *this << " cannot sign" << form << ": " << e.what() << std::endl;
		return false;
	}
	return true;
}

bool	Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executes " << form << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << *this << " cannot execute " << form << ": " << e.what() << std::endl;
		return false;
	}
	return true;
}

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &rhs)
{
	ost // << "[" << &rhs << "]"
		<< " Bureaucrat [" << rhs.getName() << "]"
		<< "(" << rhs.getGrade() << ")";
	return ost;
}

