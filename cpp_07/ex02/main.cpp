#include <iostream>
#include <sstream>
#include <string>
#include "Array.hpp"

#ifndef MAX_VAL
# define MAX_VAL 750
#endif

int main(int, char**)
{
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		std::cout << numbers.size() << numbers << std::endl;
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
			tmp.back() = 0;
			std::cout << numbers.size() << numbers << std::endl;
			std::cout << tmp.size() << tmp << std::endl;
			std::cout << test.size() << test << std::endl;
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}

		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << numbers << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		std::cout << numbers << std::endl;
		delete [] mirror;
	}
	std::cout << std::endl;
	{
		Array<std::string> array(MAX_VAL);
		std::cout << array.size() << array << std::endl;
		array.fill("hello");
		std::cout << array.size() << array << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::stringstream s;
			s << i;
			array[i] += " " + s.str();
		}
		std::cout << array.size() << array << std::endl;
	}

#if LEAKS
	system("leaks exe");
#endif
	return 0;
}
