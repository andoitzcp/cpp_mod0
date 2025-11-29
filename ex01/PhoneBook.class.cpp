#include "PhoneBook.class.hpp"
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(void)
{
    this->_i = 0;
    return;
}

PhoneBook::~PhoneBook(void) {return;}

void PhoneBook::setContact(void)
{
    int i = this->_i % this->_capacity;
    std::cout << "Creating new contact...\n";
    this->_list[i].firstName = _getUserInput("\tFirst name: ");
    this->_list[i].lastName = _getUserInput("\tLast name: ");
    this->_list[i].nickName = _getUserInput("\tNickname: ");
    this->_list[i].phoneNumber = _getUserInput("\tPhone number: ");
    this->_list[i].darkestSecret= _getUserInput("\tDarkest secret: ");

    ++(this->_i);
    std::cout << "Contact added." << std::endl;
    return ;
}

std::string PhoneBook::_getUserInput(std::string const prompt) const
{
    std::string userInput;

    std::cout << prompt;
    while (1)
    {
        std::getline(std::cin, userInput);
        if (!userInput.empty())
            return (userInput);
        std::cout << "This field can't be empty!" << std::endl;
    }
}

void PhoneBook::printPhoneBook() const
{
    if (this->_i == 0)
    {
        std::cout << "PhoneBook is empty, nothing to search." << std::endl;
        return ;
    }

    std::cout << "|" << std::setw(10) << "index";
    std::cout << "|" << std::setw(10) << "first name";
    std::cout << "|" << std::setw(10) << "last name";
    std::cout << "|" << std::setw(10) << "nickname";
    std::cout << "|\n";

    int i = 0;
    while (i < this->_capacity && i < this->_i)
        _printContactEntry(i++);

    int j;
    while (1)
    {
        std::string userInputIndex = _getUserInput("Select an index: ");
        std::stringstream ss(userInputIndex);
        if (ss >> j && ss.eof() && j >= 0 && j <= this->_capacity && j < this->_i)
        {
            _printContactDetail(j);
            return ;
        }
        std::cout << "Invalid input" << std::endl;
    }
    return ;
}

void PhoneBook::_printContactEntry(int i) const
{
    std::string fn;
    std::string ln;
    std::string nn;

    fn = this->_list[i].firstName;
    if (fn.length() > 10)
        fn = fn.substr(0, 9) + '.';
    ln = this->_list[i].lastName;
    if (ln.length() > 10)
        ln = ln.substr(0, 9) + '.';
    nn = this->_list[i].nickName;
    if (nn.length() > 10)
        nn = nn.substr(0, 9) + '.';
    std::cout << "|" << std::setw(10) << i;
    std::cout << "|" << std::setw(10) << fn;
    std::cout << "|" << std::setw(10) << ln;
    std::cout << "|" << std::setw(10) << nn;
    std::cout << "|\n";
    return ;
}

void PhoneBook::_printContactDetail(int i) const
{
    std::cout << std::setw(16) << "#: " << i << '\n';
    std::cout << std::setw(16) << "First name: "
              << this->_list[i].firstName << '\n';
    std::cout << std::setw(16) << "Last name: "
              << this->_list[i].lastName << '\n';
    std::cout << std::setw(16) << "Nickname: "
              << this->_list[i].nickName << '\n';
    std::cout << std::setw(16) << "Phone number: "
              << this->_list[i].phoneNumber << '\n';
    std::cout << std::setw(16) << "Darkest secret: "
              << this->_list[i].darkestSecret << '\n';
}
