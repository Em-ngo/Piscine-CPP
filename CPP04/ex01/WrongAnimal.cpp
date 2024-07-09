/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:49:21 by engo              #+#    #+#             */
/*   Updated: 2024/07/09 23:14:02 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal was born" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &autre) {
    *this = autre;
    std::cout << "Another WrongAnimal was born" << std::endl;
    return;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &autre) {
    if (this != &autre)
        this->type = autre.type;
    return *this;
}

std::string const WrongAnimal::getType() const {
    return type;
}

void    WrongAnimal::makeSound() const {
    std::cout << GREEN << this->getType() << " \033[0;32msaid : [wrong animal noises] !\033[00m" << std::endl;
}