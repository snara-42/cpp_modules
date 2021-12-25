#include "Karen.hpp"
#include <cstddef>
#include <iostream>
#include <string>

Karen::Karen()
{}

Karen::~Karen()
{}

Karen::Karen(Karen const &other)
{
    *this = other;
}

Karen &Karen::operator=(Karen const &other)
{
	if (this != &other)
		;
    return *this;
}

static void	insignificant(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Karen::debug(void)
{
	std::cout << "I love to get extra grated radish for my oroshi-udon. I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "I cannot believe adding extra grated radish cost more money. You don’t put enough!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra radish for free. I’ve been eating udon here for years!" << std::endl;
}

void	Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now!" << std::endl;
}

void	Karen::complain(std::string level)
{
	const size_t N = 4;
	typedef	void (*t_func)(void);
	t_func	f = &insignificant;
	const struct {
		std::string	level;
		t_func		func;
	}	pair[] = {
		{"DEBUG",debug}, {"INFO",info}, {"WARNING",warning}, {"ERROR",error},
	};

	for (size_t i = 0; i < N; ++i)
	{
		level == pair[i].level && (f = pair[i].func);
	}
	f();
}
