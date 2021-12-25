#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::GradeTooHighException::GradeTooHighException(char const *message): std::out_of_range(message) {}
Form::GradeTooLowException::GradeTooLowException(char const *message): std::out_of_range(message) {}
Form::WithoutSignException::WithoutSignException(char const *message): std::out_of_range(message) {}

Form::Form(std::string const &name, int const grade_sign, int const grade_execute, std::string const &target)
	: _name(name), _is_signed(false), _min_grade_sign(grade_sign), _min_grade_execute(grade_execute), _target(target)
{
	assertGradeIsInRange(_min_grade_sign);
	assertGradeIsInRange(_min_grade_execute);
}

Form::~Form()
{
}

Form::Form(Form const &rhs)
	: _name(rhs._name), _is_signed(rhs._is_signed), _min_grade_sign(rhs._min_grade_sign), _min_grade_execute(rhs._min_grade_execute), _target(rhs._target)
{
}

Form &Form::operator=(Form const &rhs)
{
	assertGradeIsInRange(rhs._min_grade_sign);
	assertGradeIsInRange(rhs._min_grade_execute);
    if (this != &rhs)
    {
		const_cast<std::string&>(this->_name) = rhs._name;
		const_cast<std::string&>(this->_target) = rhs._target;
		this->_is_signed = rhs._is_signed;
		this->_min_grade_sign = rhs._min_grade_sign;
		this->_min_grade_execute = rhs._min_grade_execute;
    }
    return *this;
}

std::string const &	Form::getName() const
{
	return this->_name;
}
std::string const &	Form::getTarget() const
{
	return this->_target;
}
int	Form::getSignGrade() const
{
	return this->_min_grade_sign;
}
int	Form::getExecuteGrade() const
{
	return this->_min_grade_execute;
}
bool	Form::isSigned() const
{
	return this->_is_signed;
}

void	Form::assertGradeIsInRange(int grade)
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
void	Form::assertExecutable(Bureaucrat const &crat) const
{
	if (this->_min_grade_execute < crat.getGrade())
	{
		throw GradeTooLowException("grade too low to execute");
	}
	if (!this->_is_signed)
	{
		throw WithoutSignException("Form not signed");
	}
}

bool	Form::beSigned(Bureaucrat const &crat)
{
	if (this->_min_grade_sign < crat.getGrade())
	{
		throw GradeTooLowException("grade too low to sign");
	}
	if (this->_is_signed)
	{
		std::cout << *this <<  " already" << std::endl;
	}
	this->_is_signed = true;
	return true;
}

std::ostream &operator<<(std::ostream &ost, Form const &rhs)
{
	ost // << "[" << &rhs << "]"
		<< " Form[" << rhs.getName() << "]"
		<< " target[" << rhs.getTarget() << "]"
		<< " (" << rhs.getSignGrade() << " sign," << rhs.getExecuteGrade() << " exec) "
		<< (rhs.isSigned() ? "(SIGNED)" : "(NOT SIGNED)");
	return ost;
}
