#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: Form(name(), k_min_grade_sign, k_min_grade_execute, target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs)
	: Form(rhs)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
    {
		this->Form::operator=(rhs);
    }
    return *this;
}

std::string const	PresidentialPardonForm::name()
{
	return std::string("presidential pardon");
}

bool	PresidentialPardonForm::execute(Bureaucrat const &crat) const
{
	assertExecutable(crat);
	
	std::cout << "Zafod Beeblebrox hereby pardoneth " << "[" <<  this->getTarget() << "]!" << std::endl;
	return true;
}
