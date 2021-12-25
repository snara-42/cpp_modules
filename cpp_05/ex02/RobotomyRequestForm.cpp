#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: Form(name(), k_min_grade_sign, k_min_grade_execute, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs)
	: Form(rhs)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
    {
		this->Form::operator=(rhs);
    }
    return *this;
}

std::string const	RobotomyRequestForm::name()
{
	return std::string("robotomy request");
}

bool	RobotomyRequestForm::execute(Bureaucrat const &crat) const
{
	assertExecutable(crat);

	int n = std::rand();

	std::cout << "drii";
	for (int i = n % 8; i; --i) { std::cout << "l"; }
	std::cout << "...";

	if (n % 2)
	{
		std::cout << "[" <<  this->getTarget() << "] has been successfully robotomized!" << std::endl;
	}
	else
	{
		std::cout << "[" <<  this->getTarget() << "] requiescat in pace, amen. +" << std::endl;
	}
	return true;
}
