#include "Timer.hpp"
#include <sstream>
#include <ctime>
#include <sys/time.h>

static clock_t	operator-(const timeval &a, const timeval &b)
{
	return (a.tv_sec - b.tv_sec) * 1000000 + (a.tv_usec - b.tv_usec);
}

Timer::Timer(const string &msg):
	start(), end(), msg(msg)
{
	gettimeofday(&start, NULL);
}

Timer::~Timer()
{
}

Timer::Timer(Timer const &rhs)
{
	*this = rhs;
}

Timer &Timer::operator=(Timer const &rhs)
{
	if (this != &rhs)
	{
		start = rhs.start;
		msg = rhs.msg;
	}
	return *this;
}

void	Timer::stop()
{
	gettimeofday(&end, NULL);
}

std::string Timer::to_string()
{
	if (end - timeval() == 0)
		gettimeofday(&end, NULL);
	clock_t	dur = (end - start);
	std::stringstream	sst;
	sst << msg << dur << " us";
	return sst.str();
}

std::ostream &operator<<(std::ostream &ost, Timer &rhs)
{
	ost << rhs.to_string();
	return ost;
}
