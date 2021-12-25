#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	std::srand(std::time(NULL));
	try
	{
		PresidentialPardonForm	p("42tokyo");
		RobotomyRequestForm		r("42tokyo");
		ShrubberyCreationForm	s("42tokyo");
		std::cout
			<< p << std::endl
			<< r << std::endl
			<< s << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	int	testb[] = {42,150,146,145,73,72,26,25,1};
	int	testn[] = {150,6,138,137,46,45,6,5,1};

	for (int i = 0; i < 9; ++i)
	{
		int b = testb[i];
		int n = testn[i];
		try
		{
			Bureaucrat	bun("bun", b), nop("nop", n);
			ShrubberyCreationForm	s("42tokyo");
			RobotomyRequestForm		r("42tokyo");
			PresidentialPardonForm	p("42tokyo");

			bun.signForm(s); nop.executeForm(s);
			bun.signForm(r); nop.executeForm(r);
			bun.signForm(p); nop.executeForm(p);
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << " " << b << " " << n << std::endl;
		}
		std::cout << std::endl;
	}

}
