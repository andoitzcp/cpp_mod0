#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main(void)
{
    std::string inputCommand;
    PhoneBook pb;

    while (1)
    {
        std::getline(std::cin, inputCommand);
        if (inputCommand.compare("ADD") == 0)
            pb.setContact();
        else if (inputCommand.compare("SEARCH") == 0)
            pb.printPhoneBook();
        else if (inputCommand.compare("EXIT") == 0)
            break;
        else
            continue ;
    }

    return 0;
}


