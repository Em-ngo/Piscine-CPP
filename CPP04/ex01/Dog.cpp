/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:00 by engo              #+#    #+#             */
/*   Updated: 2024/07/02 23:27:51 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << GREEN << "Dog was born" << RESET << std::endl;
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
    std::cout << GREEN << "Dog destructor called" << RESET << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << "\033[0;32mWoof Woof!\033[00m" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->brain);
}