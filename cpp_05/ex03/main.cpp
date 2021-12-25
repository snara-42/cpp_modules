#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"

int	main()
{
	std::srand(std::time(NULL));
	try
	{
		Intern	it;
		Intern	j(it);
		Intern	k;
		k = j;

		Form *s = it.makeForm("shrubbery creation", "42tokyo");
		std::cout << s << *s << std::endl;
		delete s;
		Form *r = it.makeForm("robotomy request", "42tokyo");
		std::cout << r << *r << std::endl;
		delete r;
		Form *p = it.makeForm("presidential pardon", "42tokyo");
		std::cout << p << *p << std::endl;
		delete p;
		Form *n = it.makeForm("segmentation formt", "42tokyo");
		std::cout << n << std::endl;
		delete n;
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
			Intern	it;
			Bureaucrat	bun("bun", b), nop("nop", n);

			Form *s = it.makeForm("shrubbery creation", "42tokyo");
			bun.signForm(*s); nop.executeForm(*s);
			delete s;
			Form *r = it.makeForm("robotomy request", "42tokyo");
			bun.signForm(*r); nop.executeForm(*r);
			delete r;
			Form *p = it.makeForm("presidential pardon", "42tokyo");
			bun.signForm(*p); nop.executeForm(*p);
			delete p;
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << " " << b << " " << n << std::endl;
		}
		std::cout << std::endl;
	}
#if LEAKS
	system("leaks exe");
#endif
}
