#include "iter.hpp"
#include <iostream>
#include <string>

#define N 6

template<typename T>
void print(T const &x) { std::cout << x << " ";}

template<typename T>
void triplex(T &x) { x += x + x;}

template<typename T>
void caesar(T x) { std::cout << static_cast<T>((x + 3) % 128) << ' ';}

void strcaesar(std::string s) {
	iter(s.c_str(), s.size(), caesar<char>);
	std::cout << " ";
}

int main( void )
{
	{
		int	array[N] = {0, 1, 2, 3, 4, 5};
		iter(array, N, print);
		std::cout << std::endl;
		iter(array, N, triplex);
		iter(array, N, print);
		std::cout << std::endl;
		iter(array, N, caesar<int>);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::string array[N] = {"quarante","deux","1/","cloqv","qtl","qlhvlz"};
		iter(array, N, print);
		std::cout << std::endl;
		iter(array, N, strcaesar);
		std::cout << std::endl;
		iter(array, N, triplex);
		iter(array, N, print);
		std::cout << std::endl;
	}
	return 0;
}
