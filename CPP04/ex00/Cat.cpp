/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:00 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 17:15:28 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << "Cat was born" << std::endl;
}

Cat::Cat(Cat const &autre) : Animal() {
    *this = autre;
    return ;
}

Cat &Cat::operator=(Cat const &autre) {
    this->type = autre.type;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miaou!" << std::endl;
}