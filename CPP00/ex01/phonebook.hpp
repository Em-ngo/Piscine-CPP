/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:35:32 by engo              #+#    #+#             */
/*   Updated: 2024/04/24 17:42:06 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
# include "contact.hpp"

class Phonebook {

private: 

    static const size_t MAX_CONTACTS = 3;
    Contact contacts[MAX_CONTACTS];
    size_t nextIndex;
    std::string truncateString(std::string str, size_t width = 10);


public:
    
    Phonebook();
    ~Phonebook();

    void addContact(Contact contact);
    void searchContact(int index);
    void displayContacts();
};


#endif