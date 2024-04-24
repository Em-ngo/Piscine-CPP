/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:35:27 by engo              #+#    #+#             */
/*   Updated: 2024/04/24 17:57:26 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <cstdio>


Phonebook::Phonebook() :nextIndex(0) {
}


void Phonebook::addContact(Contact contact) {
    contacts[nextIndex] = contact;
    nextIndex = (nextIndex + 1) % MAX_CONTACTS;
    printf("%lu", nextIndex);
    std::cout << "\033[0;32mContact added successfully!\033[00m" << std::endl;
}



void Phonebook::displayContacts() {
    // En-tête avec la largeur de colonne fixée à 10 caractères et alignement à droite
    std::cout << "\033[0;95m"
              << std::setw(10) << std::right << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    std::cout << "-------------------------------------------\033[00m"<< std::endl;

    size_t startIndex = nextIndex;
    size_t displayedIndex = 1;

    for (size_t i = 0; i < MAX_CONTACTS; ++i) {
        size_t currentIndex = (startIndex + i) % MAX_CONTACTS;

        if (!contacts[currentIndex].getFirstName().empty()) {
            // Chaque champ est affiché avec une largeur fixée à 10 caractères et aligné à droite
            std::cout << std::setw(10) << std::right << displayedIndex << "\033[0;95m|\033[00m"
                      << std::setw(10) << truncateString(contacts[currentIndex].getFirstName()) << "\033[0;95m|\033[00m"
                      << std::setw(10) << truncateString(contacts[currentIndex].getLastName()) << "\033[0;95m|\033[00m"
                      << std::setw(10) << truncateString(contacts[currentIndex].getNickname()) << std::endl;
            ++displayedIndex;
        }
    }
}

std::string Phonebook::truncateString(std::string str, size_t width) {
   if (str.length() > width) {
        return str.substr(0, width - 1) + '.';
    } else {
        // Make sure the string is right-aligned to match the width.
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