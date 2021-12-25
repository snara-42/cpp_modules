#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>

template<typename T>
typename T::iterator easyfind(T& t, const int val)
{
	typename T::iterator it = std::find(t.begin(), t.end(), val);
	if (it == t.end())
		throw std::runtime_error("value not found");
	return it;
}

template<typename T>
typename T::const_iterator easyfind(const T& t, const int val)
{
	typename T::const_iterator it = std::find(t.begin(), t.end(), val);
	if (it == t.end())
		throw std::runtime_error("value not found");
	return it;
}

template<typename T, typename V>
typename T::iterator easyfind(T& t, const V& val)
{
	typename T::iterator it = std::find(t.begin(), t.end(), val);
	if (it == t.end())
		throw std::runtime_error("value not found");
	return it;
}

template<typename T, typename V>
typename T::const_iterator easyfind(const T& t, const V& val)
{
	typename T::const_iterator it = std::find(t.begin(), t.end(), val);
	if (it == t.end())
		throw std::runtime_error("value not found");
	return it;
}

#endif /* EASYFIND_HPP */

