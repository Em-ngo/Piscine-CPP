/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:00 by engo              #+#    #+#             */
/*   Updated: 2024/06/25 15:28:44 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << GREEN << "Dog was born" << RESET << std::endl;
    this->brain = new Brain();
}

Dog::Dog(Dog const &autre) : Animal() {
    *this = autre;
    brain = new Brain(*autre.brain);
    return ;
}

Dog &Dog::operator=(Dog const &autre) {
    this->type = autre.type;
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "\033[0;32mWoof Woof!\033[00m" << std::endl;
}