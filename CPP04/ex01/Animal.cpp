/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:39 by engo              #+#    #+#             */
/*   Updated: 2024/06/25 15:10:13 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    type = "Animal";
    std::cout << L_BLUE << "Animal was born" << RESET << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &autre) {
    *this = autre;
    return ;
}

std::string const	Animal::getType() const {
	return (this->type);
}


Animal &Animal::operator=(const Animal &autre) {
    this->type = autre.type;
    return *this;
}


void Animal::makeSound() const {
    std::cout << "\033[0;32mAnimal's sound\033[00m" << std::endl;
}