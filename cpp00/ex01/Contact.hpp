#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
private:

public:
    Contact();
    virtual ~Contact();
    Contact(Contact const &other);
    Contact &operator=(Contact const &other);
};

#endif
