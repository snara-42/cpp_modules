#include "Phonebook.hpp"

Phonebook::Phonebook()
{
}

Phonebook::~Phonebook()
{
}

Phonebook::Phonebook(Phonebook const &other)
{
    *this = other;
}

Phonebook &Phonebook::operator=(Phonebook const &other)
{
    if (this != &other)
    {
    }
    return *this;
}
