#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"


class PhoneBook
{
    public:

        PhoneBook(void);
        ~PhoneBook(void);
        
        void setContact(void);
        void printPhoneBook(void) const;

    private:
        static const int _capacity = 8;
        int _i;
        Contact _list[_capacity];
        std::string _getUserInput(std::string const prompt) const;
        void _printContactEntry(int i) const;
        void _printContactDetail(int i) const;
        
};

#endif // PHONEBOOK_H
