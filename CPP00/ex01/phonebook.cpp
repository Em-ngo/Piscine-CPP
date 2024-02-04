/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:35:27 by engo              #+#    #+#             */
/*   Updated: 2024/02/04 16:08:59 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() :nextIndex(0) {
}

void Phonebook::addContact(const Contact contact) {
   contacts[nextIndex] = contact;
    nextIndex = (nextIndex + 1) % MAX_CONTACTS;
    std::cout << "Contact added successfully!" << std::endl;
}


void Phonebook::displayContacts() {
    std::cout << "\033[0;95m Index\t| First Name\t| Last Name\t| Nickname" << std::endl;
    std::cout << "-----------------------------------------------\033[00m" << std::endl;

    size_t startIndex = nextIndex;

    size_t displayedIndex = 1;

    for (size_t i = 0; i < MAX_CONTACTS; ++i) {
        size_t currentIndex = (startIndex + i) % MAX_CONTACTS;

        // Display the contact only if it exists
        if (!contacts[currentIndex].getFirstName().empty()) {
            std::cout << displayedIndex << "\t" << truncateString(contacts[currentIndex].getFirstName())
                      << "\t\t" << truncateString(contacts[currentIndex].getLastName())
                      << "\t\t" << truncateString(contacts[currentIndex].getNickname()) << std::endl;

            // Increment the displayed index for the next contact
            ++displayedIndex;
        }
    }
}

std::string Phonebook::truncateString(std::string str, size_t width) {
    return (str.length() > width) ? str.substr(0,  - 1) + '.' : str;
}

void Phonebook::searchContact(int index) {
    if (index >= 1 && (size_t)(index - 1) < MAX_CONTACTS) {
        Contact& contact = contacts[index - 1];
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    } else {
        std::cout << "Invalid index. Please try again." << std::endl;
    }
}


Phonebook::~Phonebook() {
}