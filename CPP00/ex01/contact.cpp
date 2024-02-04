/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:17:49 by engo              #+#    #+#             */
/*   Updated: 2024/02/03 16:46:12 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>

Contact::Contact() {

}

void Contact::setFirstName(std::string name) {
    
     FirstName = name; 
}

void Contact::setLastName(std::string name) {
    
    LastName = name; 

}

void Contact::setNickname(std::string nick) {
    
    NickName = nick;
     
}

void Contact::setPhoneNumber(std::string number) { 
    
    NumberPhone = number;

}

void Contact::setDarkestSecret(std::string secret) {

    DarkestSecret = secret; 
}   

std::string Contact::getFirstName() {
    return FirstName; 
}

std::string Contact::getLastName() { 
    
    return LastName; 
}

std::string Contact::getNickname() { 
    
    return NickName;
}

std::string Contact::getPhoneNumber() { 
    
    return NumberPhone;
}

std::string Contact::getDarkestSecret() { 
    
    return DarkestSecret; 
}

Contact::~Contact() {

}