#include "Bureaucrat.hpp"
#include <chrono>
#include <string>

int	main()
{
	int	test[] = {-2147483648,0,1,42,142,150,151,2147483647};

	for (int i = 0; i < 8; ++i)
	{
		int n = test[i];
		try
		{
			Bureaucrat nop("nop", n);
			Bureaucrat bun("bun");
			bun = nop;
			std::cout <<   n  << " " << nop << " " << bun << std::endl;
			std::cout << --n  << " " << ++nop << std::endl;
			std::cout << --n  << " " << ++nop << std::endl;
			std::cout <<(n+=3)<< " " << (--(--(--nop))) << std::endl;
			std::cout << ++n  << " " << --nop << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << " " << n<< std::endl;
		}
	}
}
