/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:39:46 by engo              #+#    #+#             */
/*   Updated: 2024/02/04 16:00:24 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

int main() {
	
    Phonebook phonebook;

    while (1) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::string command;
        std::getline(std::cin, command);

        if (command == "ADD" || command == "add") {
			
            Contact newContact;

            std::string input;
			
            std::cout << "Enter First Name: ";
            std::getline(std::cin, input);
            newContact.setFirstName(input);

            std::cout << "Enter Last Name: ";
            std::getline(std::cin, input);
            newContact.setLastName(input);

            std::cout << "Enter Nickname: ";
            std::getline(std::cin, input);
            newContact.setNickname(input);

            std::cout << "Enter Phone Number: ";
            std::getline(std::cin, input);
            newContact.setPhoneNumber(input);

            std::cout << "Enter Darkest Secret: ";
            std::getline(std::cin, input);
            newContact.setDarkestSecret(input);

            phonebook.addContact(newContact);
        } 
		else if (command == "SEARCH" || command == "search") {
			
			phonebook.displayContacts();

			std::string userInput;
			std::cout << "Enter index to display (or type 'EXIT' to go back): ";
            std::getline(std::cin, userInput);
			if (userInput == "EXIT" || userInput == "exit") {
				continue;
			}

			std::istringstream iss(userInput);
			int index;

			if (iss >> index) {
				
				phonebook.searchContact(index);
			} 
			else {
				
				std::cout << "Invalid input. Please enter a valid index or 'EXIT'." << std::endl;
				std::cin.clear(); 
			}
		}
		else if (command == "EXIT" || command == "exit") {
			
            std::cout << "Exiting program. Contacts will be lost." << std::endl;
            break;
        } 
		else {
			
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}