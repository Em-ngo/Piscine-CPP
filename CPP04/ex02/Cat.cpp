/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:00 by engo              #+#    #+#             */
/*   Updated: 2024/07/03 11:25:15 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->brain = new Brain();
    this->type = "Cat";
    std::cout << YELLOW << "Cat was born" << RESET << std::endl;
}

Cat::Cat(Cat const &autre) : Animal() {
    *this = autre;
    std::cout << YELLOW << "Another Cat was born" << RESET << std::endl;
    brain = new Brain(*autre.brain);
    return ;
}

Cat &Cat::operator=(Cat const &autre) {
    this->type = autre.type;
    return *this;
}

Cat::~Cat() {
    std::cout << YELLOW << "Cat destructor called" << RESET << std::endl;
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << "\033[0;32mMiaou!\033[00m" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->brain);
}