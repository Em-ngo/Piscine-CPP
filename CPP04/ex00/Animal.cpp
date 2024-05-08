/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:39 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 17:15:18 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    type = "Animal";
    std::cout << "Animal was called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &autre) {
    *this = autre;
    return ;
}

std::string const	Animal::getType() const {
	return (type);
}


Animal &Animal::operator=(const Animal &autre) {
    this->type = autre.type;
    return *this;
}


void Animal::makeSound() const {
    std::cout << "Animal's sound" << std::endl;
}