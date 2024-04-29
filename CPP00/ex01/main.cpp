/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:39:46 by engo              #+#    #+#             */
/*   Updated: 2024/04/25 19:28:31 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

void cleanUpAndExit() {
    std::exit(0);
}

void signalHandler(int signal) {
    if (signal == SIGINT) {
        cleanUpAndExit();
    }
}

int main() {
	
    Phonebook phonebook;

    while (1) {
        
        if (std::cin.eof())
                break;
        std::cout << "\033[0;33mEnter command (ADD, SEARCH, EXIT): \033[00m";
        std::string command;
        std::getline(std::cin, command);
        std::signal(SIGINT, signalHandler);
        

        
        if (command == "ADD" || command == "add") {
			
            Contact newContact;

            std::string input;
            if (std::cin.eof())
                break;
            std::cout << "\033[0;36mEnter First Name: \033[00m";
            while (std::getline(std::cin, input) && input.empty()) {
                std::cout << "\033[0;31mFirst Name cannot be empty.\033[00m \n \033[0;36mPlease enter First Name: \033[00m";
            }
            newContact.setFirstName(input);

            if (std::cin.eof())
                break;
            std::cout << "\033[0;36mEnter Last Name: \033[00m";
            while (std::getline(std::cin, input) && input.empty()) {
                std::cout << "\033[0;31mLast Name cannot be empty.\033[00m \n \033[0;36mPlease enter Last Name: \033[00m";
            }
            newContact.setLastName(input);

            if (std::cin.eof())
                break;
            std::cout << "\033[0;36mEnter Nickname: \033[00m";
            while (std::getline(std::cin, input) && input.empty()) {
                std::cout << "\033[0;31mNickname cannot be empty.\033[00m \n \033[0;36mPlease enter Nickname: \033[00m";
            }
            newContact.setNickname(input);
            
            if (std::cin.eof())
                break;
            std::cout << "\033[0;36mEnter Phone Number: \033[00m";
            while (std::getline(std::cin, input) && input.empty()) {
                std::cout << "\033[0;31mPhone Number cannot be empty.\033[00m \n \033[0;36mPlease enter Phone Number: \033[00m";
            }
            newContact.setPhoneNumber(input);

            if (std::cin.eof())
                break;
            std::cout << "\033[0;36mEnter Darkest Secret: \033[00m";
            while (std::getline(std::cin, input) && input.empty()) {
                std::cout << "\033[0;31mDarkest Secret cannot be empty.\033[00m \n \033[0;36mPlease enter Darkest Secret: \033[00m";
            }
            newContact.setDarkestSecret(input);

            phonebook.addContact(newContact);
        } 
		else if (command == "SEARCH" || command == "search") {
			
            if (std::cin.eof())
                break;
			phonebook.displayContacts();
            
			std::string userInput;
			std::cout << "\033[0;33mEnter index to display (or type 'EXIT' to go back): \033[00m";
            while (std::getline(std::cin, userInput) && userInput.empty()) {
                std::cout << "\033[0;33mEnter index to display (or type 'EXIT' to go back): \033[00m";
			    if (userInput == "EXIT" || userInput == "exit") {
				    continue;
                }
			}

			std::istringstream iss(userInput);
			int index;

			if (iss >> index) {
				
				phonebook.searchContact(index);
			} 
			else {
                
				if (std::cin.eof())
                break;
				std::cout << "\033[0;31mInvalid input. Please enter a valid index or 'EXIT'.\033[00m" << std::endl;
			}
		}
		else if (command == "EXIT" || command == "exit") {
            
            if (std::cin.eof())
                break;
            std::cout << "\033[0;31mExiting program. Contacts will be lost.\033[00m" << std::endl;
            break;
        } 
		else {
            if (std::cin.eof())
                break;
            std::cout << "\033[0;31mInvalid command. Please try again.\033[00m" << std::endl;
        } 
    }
    return 0;
}