#include "Data.hpp"
#include <iomanip>
#include <sstream>

Data::Data(std::string const &str): s1(str), n(rand()), s2(str)
{
	for (size_t i = 0; i < s2.capacity(); ++i)
	{
		s2[i] = (s2[i] + rand()) % 93 + '!';
	}
}

Data::~Data()
{
}

Data::Data(Data const &rhs)
{
	*this = rhs;
}

Data &Data::operator=(Data const &rhs)
{
	if (this != &rhs)
	{
		this->s1 = rhs.s1;
		this->n  = rhs.n;
		this->s2 = rhs.s2;
	}
	return *this;
}

std::string Data::to_string() const
{
	std::stringstream	sst;
	sst << "[" << s1 << ", " << n << ", " << s2 <<"]";
	return sst.str();
}

std::ostream &operator<<(std::ostream &ost, Data const &rhs)
{
	ost << rhs.to_string();
	return ost;
}

uintptr_t	serialize(Data *ptr)
{
	uintptr_t	raw = reinterpret_cast<uintptr_t>(ptr);
	std::cout << "serialize:  " << ptr << " -> " << std::hex << raw << " " << *ptr << std::endl;
	return raw;
}

Data*		deserialize(uintptr_t raw)
{
	Data	*ptr = reinterpret_cast<Data*>(raw);
	std::cout << "deserialize:" << std::hex << raw << " -> " << ptr << " " <<  *ptr << std::endl;
	return ptr;
}

