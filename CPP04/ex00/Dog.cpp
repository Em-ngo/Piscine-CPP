/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:00 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 17:15:40 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "Dog was born" << std::endl;
}

Dog::Dog(Dog const &autre) : Animal() {
    *this = autre;
    return ;
}

Dog &Dog::operator=(Dog const &autre) {
    this->type = autre.type;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}