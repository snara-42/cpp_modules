#include <string>
#include <iostream>

int	main()
{
	std::string	 str = "HI THIS IS BRAIN";
	std::string	&ref = str;
	std::string	*ptr = &str;

	std::cout << "&str: " << &str << std::endl;
	std::cout << "&ref: " << &ref << std::endl;
	std::cout << " ptr: " <<  ptr << std::endl;
	std::cout << std::endl;
	std::cout << " str: " <<  str << std::endl;
	std::cout << " ref: " <<  ref << std::endl;
	std::cout << "*ptr: " << *ptr << std::endl;

	return 0;
}
