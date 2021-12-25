#include "Karen.hpp"
#include <cstddef>
#include <iostream>
#include <string>

typedef	void (*t_func)(void);

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
	std::cout << "DEBUG :   I love to get extra grated radish for my oroshi-udon. I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "INFO :    I cannot believe adding extra grated radish cost more money. You don’t put enough!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "WARNING : I deserve some extra radish for free. I’ve been eating udon here for years!" << std::endl;
}

void	Karen::error(void)
{
	std::cout << "ERROR :   This is unacceptable, call the manager Now!" << std::endl;
}

void	Karen::complain(std::string level)
{
	t_func	f = &insignificant;
	const struct {
		std::string	level;
		t_func		func;
	}	pair[] = {
		{"ERROR",error}, {"WARNING",warning}, {"INFO",info}, {"DEBUG",debug},
	};

	for (size_t i = 0; i < NUM_LEVEL; ++i)
	{
		level == pair[i].level && (f = pair[i].func);
	}
	f();
}

void	Karen::filter(std::string level)
{
	size_t	i = 0;
	const struct {
		std::string	level;
		t_func		func;
	}	pair[] = {
		{"ERROR",error}, {"WARNING",warning}, {"INFO",info}, {"DEBUG",debug},
	};

	for (i = 0; i < NUM_LEVEL && level != pair[i].level; ++i)
		;
	switch (i) {
		case DEBUG:		pair[DEBUG].func();
		case INFO:		pair[INFO].func();
		case WARNING:	pair[WARNING].func();
		case ERROR:		pair[ERROR].func(); break;
		default:		insignificant(); break;
	}
}
