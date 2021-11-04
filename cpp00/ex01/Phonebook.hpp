#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class Phonebook
{
private:

public:
    Phonebook();
    virtual ~Phonebook();
    Phonebook(Phonebook const &other);
    Phonebook &operator=(Phonebook const &other);
};

#endif
