#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form(name(), k_min_grade_sign, k_min_grade_execute, target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs)
	: Form(rhs)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
    {
		this->Form::operator=(rhs);
    }
    return *this;
}

std::string const	ShrubberyCreationForm::name()
{
	return std::string("shrubbery creation");
}

bool	ShrubberyCreationForm::execute(Bureaucrat const &crat) const
{
	assertExecutable(crat);
	{
		std::ofstream	ofs;
		ofs.exceptions(std::ios::failbit | std::ios::badbit);
		ofs.open(this->getTarget() + "_shrubbery");
		ofs << "" << std::endl
			<< "-+--+--+-" << std::endl
			<< "/ \\/+\\/|\\" << std::endl
			<< std::endl;
	}
	std::cout << "shrubberies have been planted in [" <<  this->getTarget() << "]!" << std::endl;
	return true;
}
