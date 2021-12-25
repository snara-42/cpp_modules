#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>

template<typename T>
class Array
{
private:
	size_t	_len;
	size_t	_cap;
	T *		_ptr;

public:
	Array(unsigned int n = 0): _len(n), _cap(n), _ptr(new T[n]())
	{}
	
	virtual ~Array()
	{
		delete[] _ptr;
	}
	
	Array(Array const &rhs): _len(rhs._len), _cap(rhs._len), _ptr(new T[rhs._len]())
	{
		for (size_t i = 0; i < rhs._len; ++i)
		{
			this->_ptr[i] = rhs._ptr[i];
		}
	}

	Array&	operator=(Array const &rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		if (!this->_ptr || this->_cap < rhs._len)
		{
			delete[] this->_ptr;
			this->_ptr = new T[rhs._len]();
			this->_cap = rhs._len;
		}
/*		
		if (!this->_ptr)
		{
			this->_len = 0;
			this->_cap = 0;
		}
*/
		this->_len = rhs._len;
		for (size_t i = 0; i < rhs._len; ++i)
		{
			this->_ptr[i] = rhs._ptr[i];
		}
		return *this;
	}

	T&	at(size_t i)
	{
		if (i >= this->_len)
		{
			throw std::out_of_range("index out of range");
		}
		if (!this->_ptr)
		{
			throw std::runtime_error("allocation error");
		}
		return this->_ptr[i];
	}
	T const&	at(size_t i) const
	{
		if (i >= this->_len)
		{
			throw std::out_of_range("index out of range");
		}
		if (!this->_ptr)
		{
			throw std::runtime_error("allocation error");
		}
		return this->_ptr[i];
	}
	T&	operator[](size_t i)
	{
		return this->at(i);
	}
	T const& operator[](size_t i) const
	{
		return this->at(i);
	}

	T&	front()
	{
		return this->at(0);
	}
	T const&	front() const
	{
		return this->at(0);
	}
	T&	back()
	{
		return this->at(this->_len - 1);
	}
	T const&	back() const
	{
		return this->at(this->_len - 1);
	}

	bool	empty() const
	{
		return (this->_len == 0);
	}
	size_t	size() const
	{
		return this->_len;
	}
	size_t	length() const
	{
		return this->_len;
	}
	size_t	max_size() const
	{
		return this->_cap;
	}
	size_t	capacity() const
	{
		return this->_cap;
	}

	void	fill(T const& u)
	{
		for (size_t i = 0; i < this->_len; ++i)
		{
			this->_ptr[i] = u;
		}
	}


	std::string to_string() const;
};

template<typename T>
std::ostream &operator<<(std::ostream &ost, Array<T> const &rhs)
{
	for (size_t i = 0; i < rhs.size(); ++i)
	{
		ost << (i == 0 ? "[" : ", ") << rhs[i];
	}
	ost << "]";
	return ost;
}

#endif /* ARRAY_HPP */
