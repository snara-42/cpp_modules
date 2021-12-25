#include <iostream>

static std::string	&str_toupper(std::string &str) {
	for (size_t i = 0; i < str.length(); ++i) {
		str[i] = toupper(str[i]);
	}
	return str;
}

int	main(int ac, char *av[]) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; ++i) {
		std::string str(av[i]);
		std::cout << str_toupper(str);
	}
	std::cout << std::endl;
	return 0;
}
