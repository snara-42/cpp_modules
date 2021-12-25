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

	static const size_t	NUM_LEVEL = 4;
	enum {
		DEBUG = 3,
		INFO = 2,
		WARNING = 1,
		ERROR = 0
	};

public:
    Karen();
    virtual ~Karen();
    Karen(Karen const &other);
    Karen &operator=(Karen const &other);
	void	complain(std::string level);
	void	filter(std::string level);
};

#endif
