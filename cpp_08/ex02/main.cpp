#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <ios>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "mutantstack.hpp"

void	test_subject()
{
	MutantStack<int> mstack;

	std::cout << std::boolalpha << mstack << " empty:" << mstack.empty() << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << std::boolalpha << mstack << " " << mstack.top() << " empty:" << mstack.empty() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	std::cout << mstack << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::cout << mstack << std::endl;
	std::stack<int> s(mstack);
}

template<class Cont>
void	test_subject_()
{
	MutantStack<int, Cont> c;
	c.push(5);
	c.push(17);
	std::cout << c.top() << std::endl;
	c.pop();
	std::cout << c.size() << std::endl;
	c.push(3);
	c.push(5);
	c.push(737);
	//[...]
	c.push(0);

	typename MutantStack<int, Cont>::iterator it = c.begin();
	typename MutantStack<int, Cont>::iterator ite = c.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void	test_uint(unsigned N)
{
	MutantStack<unsigned> s;
	for (unsigned i = 0; i <= N; ++i)
		s.push(i);
	s.pop();
	std::cout << s << " " << s.top() << std::endl;
}

void	test_str(unsigned N)
{
	MutantStack<std::string, std::list<std::string> > s;
	for (unsigned i = 0; i <= N; ++i)
		s.push("str" + std::to_string(i));
	s.pop();
	std::cout << s << " " << s.top() << std::endl;
}

void	test_double(unsigned N)
{
	MutantStack<double, std::vector<double> > s;
	for (unsigned i = 1; i <= N; ++i)
		s.push(1.0 / i);
	std::cout << s << " " << s.top() << std::endl;
}

int main()
{
	test_subject();
	test_subject_<std::list<int> >();
	std::srand(std::time(NULL));

	std::cout << std::endl << "deque<unsigned>" << std::endl;
	for (unsigned n = 1; n <= 6; ++n)
		test_uint(1 << n);

	std::cout << std::endl << "list<string>" << std::endl;
	for (unsigned n = 1; n <= 4; ++n)
		test_str(1 << n);

	std::cout << std::endl << "vector<double>" << std::endl;
	for (unsigned n = 1; n <= 4; ++n)
		test_double(1 << n);

}
