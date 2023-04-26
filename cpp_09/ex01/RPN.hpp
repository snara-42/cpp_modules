#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <vector>

class RPN
{
private:

public:
	RPN();
	virtual ~RPN();
	RPN(RPN const &rhs);
	RPN &operator=(RPN const &rhs);
	std::string to_string() const;

	static int	calculate(std::string s);
};

std::ostream &operator<<(std::ostream &ost, RPN const &rhs);

#endif /* RPN_HPP */
