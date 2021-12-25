#ifndef HEADER_HPP
# define HEADER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

template<typename T>
const T&	min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template<typename T>
T&	min(T& a, T& b)
{
	return (a < b ? a : b);
}

template<typename T>
const T&	max(const T& a, const T& b)
{
	return (a > b ? a : b);
}

template<typename T>
T&	max(T& a, T& b)
{
	return (a > b ? a : b);
}

#endif /* HEADER_HPP */
