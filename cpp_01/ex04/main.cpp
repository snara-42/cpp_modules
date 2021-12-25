#include "Replace.hpp"
#include <atomic>

int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "usage: " << av[0] << " FILE FROM TO" << std::endl;
		return 0;
	}
	try
	{
		std::string	fname(av[1]);
		if (fname == "" || fname == "-")
		{
			Replace	r(av[2], av[3], std::cin, std::cout);
			r.replace();
		}
		else
		{
			std::ifstream	fin(fname);
			std::ofstream	fout(fname + ".replace", std::ios::out | std::ios::trunc);
			Replace	r(av[2], av[3], fin, fout);
			r.replace();
		}
	}
	catch (char const *e)
	{ std::cerr << av[0] << ": " << e << std::endl; }
	catch (...)
	{ std::cerr << av[0] << ": an error occurred" << std::endl; }
	return 0;
}
