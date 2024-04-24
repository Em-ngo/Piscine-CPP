/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:39:46 by engo              #+#    #+#             */
/*   Updated: 2024/04/24 16:11:38 by engo             ###   ########.fr       */
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
            while (std::getline(std::cin, input) && input.empty()) {
                std::cout << "\033[0;31mFirst Name cannot be empty.\033[00m \n Please enter First Name: ";
            }
            newContact.setFirstName(input);

            std::cout << "Enter Last Name: ";
            while (std::getline(std::cin, input) && input.empty()) {
                std::cout << "\033[0;31mLast Name cannot be empty.\033[00m \n Please enter Last Name: ";
            }
            newContact.setLastName(input);

            std::cout << "Enter Nickname: ";
            while (std::getline(std::cin, input) && input.empty()) {
                std::cout << "\033[0;31mNickname cannot be empty.\033[00m \n Please enter Nickname: ";
            }
            newContact.setNickname(input);

            std::cout << "Enter Phone Number: ";
            while (std::getline(std::cin, input) && input.empty()) {
                std::cout << "\033[0;31mPhone Number cannot be empty.\033[00m \n Please enter Phone Number: ";
            }
            newContact.setPhoneNumber(input);

            std::cout << "Enter Darkest Secret: ";
            while (std::getline(std::cin, input) && input.empty()) {
                std::cout << "\033[0;31mDarkest Secret cannot be empty.\033[00m \n Please enter Darkest Secret: ";
            }
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