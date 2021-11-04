#include <iostream>

namespace {
std::string	&str_upper(std::string &str) {
	for (size_t i = 0; i < str.length(); ++i) {
		str[i] = toupper(str[i]);
	}
	return str;
}
}

int	main(int ac, char *av[]) {
	if (ac <= 1) {
		std::cout << "* |}+_{:>?' FEEDBACK NOISE ~!@#$%^&*()_+ *";
	} else {
		for (int i = 1; i < ac; ++i) {
			std::string str(av[i]);
			std::cout << str_upper(str);
		}
	}
	std::cout << std::endl;
	return 0;
}
