#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	b;
		Form		f;
		std::cout << b << std::endl;
		std::cout << f << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	int	test[] = {0,1,20,21,22,42,150,151};
	Bureaucrat	nop("nop", 21);

	for (int i = 0; i < 8; ++i)
	{
		int n = test[i];
		try
		{
			Form	f("42tokyo entry",42,n);
			std::cout << f << std::endl;
			nop.signForm(f);
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << " " << n << std::endl;
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		int n = test[i];
		try
		{
			Form	f("42tokyo tig",n,42);
			std::cout << f << std::endl;
			nop.signForm(f);
			nop.signForm(f);
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << " " << n << std::endl;
		}
	}
}
