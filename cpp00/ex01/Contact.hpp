#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	private:
		enum e_info {
			FIRST_NAME	= 0,
			LAST_NAME	= 1,
			NICKNAME	= 2,
			PHONE_NUMBER	= 3,
			DARKEST_SECRET	= 4,
			NUM_INFO	= 5,
		};
		std::string _info[NUM_INFO];

	public:
		Contact();
		~Contact();
		Contact(Contact const &other);
		Contact &operator=(Contact const &other);
		std::ostream &operator<<(Contact const &contact);

		static const char *header(size_t const i);
		void print_brief(std::ostream &ost) const;
		void print_detail(std::ostream &ost) const;
		void set_info(std::istream &ist);
};

#endif
