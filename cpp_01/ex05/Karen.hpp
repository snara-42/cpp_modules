#ifndef KAREN_HPP
# define KAREN_HPP

#include <string>

class Karen
{
private:
	static void	debug(void);
	static void	info(void);
	static void	warning(void);
	static void	error(void);

public:
    Karen();
    virtual ~Karen();
    Karen(Karen const &other);
    Karen &operator=(Karen const &other);
	void	complain(std::string level);
};

#endif
