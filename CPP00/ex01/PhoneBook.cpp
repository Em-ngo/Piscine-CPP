/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:35:27 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 14:02:25 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>


PhoneBook::PhoneBook() :index_contact(0) {
}


void PhoneBook::addContact(Contact contact) {
    if (std::cin.eof())
        return;
    contacts[index_contact] = contact;
    index_contact = (index_contact + 1) % MAX_CONTACTS;
    std::cout << "\033[0;32mContact added successfully!\033[00m" << std::endl;
}



void PhoneBook::displayContacts() {
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

std::string PhoneBook::truncateString(std::string str, size_t width) {
   if (str.length() > width) {
        return str.substr(0, width - 1) + '.';
    } else {
        return std::string(width - str.length(), ' ') + str;
    }
}

void PhoneBook::searchContact(int index) {
        Contact& contact = contacts[index - 1];
    if (index <= 0 || index > 8)
        std::cout << "\033[0;31mInvalid index. Please try again.\033[00m" << std::endl;
    else if (!contact.getFirstName().empty()) {
        if (index >= 1 && (size_t)(index - 1) < MAX_CONTACTS){
            std::cout << "\033[0;34mFirst Name: \033[00m" << contact.getFirstName() << std::endl;
            std::cout << "\033[0;34mLast Name: \033[00m" << contact.getLastName() << std::endl;
            std::cout << "\033[0;34mNickname: \033[00m" << contact.getNickname() << std::endl;
            std::cout << "\033[0;34mPhone Number: \033[00m" << contact.getPhoneNumber() << std::endl;
            std::cout << "\033[0;34mDarkest Secret: \033[00m" << contact.getDarkestSecret() << std::endl;
            }
    }
    else {
        std::cout << "\033[0;31mInvalid index. Please try again.\033[00m" << std::endl;
    }
}


PhoneBook::~PhoneBook() {
}