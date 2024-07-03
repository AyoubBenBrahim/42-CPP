LOGIN/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:37:15 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/19 13:37:18 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_CLASS_H
# define PHONE_BOOK_CLASS_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

enum Commands
{
    ADD,
    SEARCH,
    EXIT,
};

class PhoneBook
{
    public:

        Contact     contacts[8];
        Commands    choosenCommand;
        int         size;
        int         oldest;

        PhoneBook();
        ~PhoneBook();

        void    drawColumn(std::string title);
        void    exitProgram(void);
        void    getCommand(void);

        void    newContact(void);
        void    pushContact(Contact tab[], Contact c);
        void    searchContact(void);
        void    stringManagment(std::string str);
        void    ctrlDSignalCheck(void);
};

#endif
