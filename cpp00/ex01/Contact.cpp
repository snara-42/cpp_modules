#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

Contact::Contact(Contact const &other)
{
    *this = other;
}

Contact &Contact::operator=(Contact const &other)
{
    if (this != &other)
    {
    }
    return *this;
}
