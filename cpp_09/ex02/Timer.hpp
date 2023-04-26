#ifndef TIMER_HPP
# define TIMER_HPP

#include <ctime>
#include <iostream>
#include <string>

using std::string;

class Timer
{
private:
	timeval	start;
	timeval	end;
	string	msg;

public:
	Timer(const string & msg);
	virtual ~Timer();
	Timer(Timer const &rhs);
	Timer &operator=(Timer const &rhs);
	std::string to_string();
	void	stop();
};

std::ostream &operator<<(std::ostream &ost, Timer &rhs);

#endif /* TIMER_HPP */
