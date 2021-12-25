#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
	private:
		const static size_t NUM_CONTACT = 8;
		Contact	_contact[NUM_CONTACT];
		size_t	_i;
		size_t	_size;

	public:
		Phonebook();
		virtual ~Phonebook();
		Phonebook(Phonebook const &other);
		Phonebook &operator=(Phonebook const &other);
		std::ostream &operator<<(std::ostream &ost);

		size_t	size() const;
		size_t	length() const;
		size_t	capacity() const;
		size_t	next_index() const;
		const Contact	&at(size_t const i) const;
		void	add(std::istream &ist, std::ostream &ost);
		int		run_cli(std::istream &cin, std::ostream &cout);
};

std::ostream &operator<<(std::ostream &ost, Phonebook const &phonebook);

#endif //PHONEBOOK_HPP

