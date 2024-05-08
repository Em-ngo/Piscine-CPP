/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:35:32 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 14:01:53 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <csignal>
# include "Contact.hpp"

class PhoneBook {

private: 

    static const size_t MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    size_t index_contact;
    std::string truncateString(std::string str, size_t width = 10);


public:
    
    PhoneBook();
    ~PhoneBook();

    void addContact(Contact contact);
    void searchContact(int index);
    void displayContacts();
};


#endif