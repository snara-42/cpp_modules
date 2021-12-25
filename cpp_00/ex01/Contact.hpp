#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>

class Contact
{
	private:
		const static size_t NUM_INFO = 5;
		enum e_info {
			FIRST_NAME	= 0,
			LAST_NAME	= 1,
			NICKNAME	= 2,
			PHONE_NUMBER	= 3,
			DARKEST_SECRET	= 4,
		};
		std::string _info[NUM_INFO];

	public:
		Contact();
		virtual ~Contact();
		Contact(Contact const &other);
		Contact &operator=(Contact const &other);

		static const std::string header_at(size_t const i);
		size_t	size() const;
		static std::string print_header();
		std::string print_brief() const;
		std::string print_detail() const;
		void	add(std::istream &ist, std::ostream &ost);
};

std::ostream &operator<<(std::ostream &ost, Contact const &contact);

#endif //CONTACT_HPP
