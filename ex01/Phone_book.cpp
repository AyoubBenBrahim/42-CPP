/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:37:06 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/19 13:37:08 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phone_book.hpp"

PhoneBook::PhoneBook()
{
    this->size = 0;
    this->oldest = 0;
}

PhoneBook::~PhoneBook()
{

};

void PhoneBook::newContact()
{
    Contact c;
    std::cout << "  First Name: ";
    std::getline(std::cin >> std::ws, c.first_name);
    std::cout << "   Last Name: ";
    std::getline(std::cin >> std::ws, c.last_name);
    std::cout << "   Nickname: ";
    std::getline(std::cin >> std::ws, c.nickname);
    std::cout << "   Phone Number: ";
    std::getline(std::cin >> std::ws, c.phone_number);
    std::cout << "   Darkest Secret: ";
    std::getline(std::cin >> std::ws, c.secret);

    this->pushContact(this->contacts, c);
}

void PhoneBook::pushContact(Contact tab[], Contact c)
{
    if (this->size == 0)
    {
        tab[0] = c;
        this->size++;
    }
    else if (this->size == 8)
    {
        tab[oldest] = c;
        if (oldest == 7)
            oldest = 0;
        else
            oldest++;
    }
    else
    {
        tab[this->size] = c;
        this->size++;
    }
}

void PhoneBook::searchContact()
{
    std::cout << "\n";
    if (this->size == 0)
    {
        std::cout << "Zero Contact in the PhoneBook !! .\n";
        return;
    }

    this->drawColumn("index");
    this->drawColumn("First Name");
    this->drawColumn("Last Name");
    this->drawColumn("Nickname");
    std::cout << "\n";

    for (int i = 0; i < this->size; i++)
    {
        stringManagment(std::to_string(i + 1));
        stringManagment(this->contacts[i].first_name);
        stringManagment(this->contacts[i].last_name);
        stringManagment(this->contacts[i].nickname);
        std::cout << "\n";
    }
    std::string string_input;
    std::cout << "\nChoose a Contact: ";
    std::getline(std::cin, string_input);
    std::cout << "\n";

    while (string_input.length() != 1 || !isdigit(string_input[0]) || (string_input[0] - 48) <= 0 || (string_input[0] - 48) > this->size)
    {
        std::cout << "Wrong Input Try again {1..." << this->size << "}: ";
        std::getline(std::cin, string_input);
    }
    std::cout << "\n";

    for (int i = 0; i < this->size; i++)
    {
        if (i == (string_input[0] - 48) - 1)
        {
            std::cout << " First Name:     " << this->contacts[i].first_name << std::endl;
            std::cout << " Last Name:      " << this->contacts[i].last_name << std::endl;
            std::cout << " Nickname:       " << this->contacts[i].nickname << std::endl;
            std::cout << " Phone Number:   " << this->contacts[i].phone_number << std::endl;
            std::cout << " Darkest Secret: " << this->contacts[i].secret << std::endl;
        }
    }
}

void PhoneBook::stringManagment(std::string str)
{
    int len;
    len = str.length();
    str = str.substr(0, 10);
    if (len > 10)
        str.at(9) = '.';
    std::cout << std::right << std::setw(10) << str << "|";
}

void PhoneBook::drawColumn(std::string title)
{
    std::cout << std::right << std::setw(10) << title << "|";
}

void PhoneBook::exitProgram()
{
    std::cout << "\n **** EXIT PhoneBook **** \n\n";
    this->~PhoneBook();
    std::exit(0);
}

void PhoneBook::getCommand()
{
    std::string input;
    int attempts = 1;
    std::cout << "\nType a Command: ";
    std::getline(std::cin >> std::ws, input);

    while (attempts <= 5)
    {
        if (input.compare("ADD") == 0)
        {
            choosenCommand = ADD;
            break;
        }
        else if (input.compare("SEARCH") == 0)
        {
            choosenCommand = SEARCH;
            break;
        }
        else if (input.compare("EXIT") == 0)
        {
            choosenCommand = EXIT;
            break;
        }
        else
        {
            std::cout << "\nValide Commands are: ADD | SEARCH | EXIT: ";
            std::getline(std::cin >> std::ws, input);
            attempts++;
            continue;
        }
    }
    if (this->choosenCommand == ADD)
    {
        this->newContact();
        getCommand();
    }
    else if (this->choosenCommand == SEARCH)
    {
        this->searchContact();
        this->getCommand();
    }
    else
        exitProgram();
}
