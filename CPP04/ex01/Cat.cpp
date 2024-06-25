/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:00 by engo              #+#    #+#             */
/*   Updated: 2024/06/25 15:28:36 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << YELLOW << "Cat was born" << RESET << std::endl;
    this->brain = new Brain();
}

Cat::Cat(Cat const &autre) : Animal() {
    *this = autre;
    brain = new Brain(*autre.brain);
    return ;
}

Cat &Cat::operator=(Cat const &autre) {
    this->type = autre.type;
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "\033[0;32mMiaou!\033[00m" << std::endl;
}