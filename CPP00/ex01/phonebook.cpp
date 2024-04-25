/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:35:27 by engo              #+#    #+#             */
/*   Updated: 2024/04/25 18:16:50 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <cstdio>


Phonebook::Phonebook() :index_contact(0) {
}


void Phonebook::addContact(Contact contact) {
    if (std::cin.eof())
        return;
    contacts[index_contact] = contact;
    index_contact = (index_contact + 1) % MAX_CONTACTS;
    std::cout << "\033[0;32mContact added successfully!\033[00m" << std::endl;
}



void Phonebook::displayContacts() {
    std::cout << "\033[0;95m"
              << std::setw(10) << std::right << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    std::cout << "-------------------------------------------\033[00m"<< std::endl;

    size_t startIndex = index_contact;

    for (size_t i = 0; i < MAX_CONTACTS; ++i) {
        size_t currentIndex = (startIndex + i) % MAX_CONTACTS;

        if (!contacts[currentIndex].getFirstName().empty()) {
            std::cout << std::setw(10) << std::right << currentIndex + 1 << "\033[0;95m|\033[00m"
                      << std::setw(10) << truncateString(contacts[currentIndex].getFirstName()) << "\033[0;95m|\033[00m"
                      << std::setw(10) << truncateString(contacts[currentIndex].getLastName()) << "\033[0;95m|\033[00m"
                      << std::setw(10) << truncateString(contacts[currentIndex].getNickname()) << std::endl;
        }
    }
}

std::string Phonebook::truncateString(std::string str, size_t width) {
   if (str.length() > width) {
        return str.substr(0, width - 1) + '.';
    } else {
        return std::string(width - str.length(), ' ') + str;
    }
}

void Phonebook::searchContact(int index) {
        Contact& contact = contacts[index - 1];
    if (index <= 0 || index > 8)
        std::cout << "Invalid index. Please try again." << std::endl;
    else if (!contact.getFirstName().empty()) {
        if (index >= 1 && (size_t)(index - 1) < MAX_CONTACTS){
            std::cout << "First Name: " << contact.getFirstName() << std::endl;
            std::cout << "Last Name: " << contact.getLastName() << std::endl;
            std::cout << "Nickname: " << contact.getNickname() << std::endl;
            std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
            }
    }
    else {
        std::cout << "Invalid index. Please try again." << std::endl;
    }
}


Phonebook::~Phonebook() {
}