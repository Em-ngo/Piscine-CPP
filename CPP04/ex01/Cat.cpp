/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:00 by engo              #+#    #+#             */
/*   Updated: 2024/07/09 22:45:04 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->brain = new Brain();
    this->type = "Cat";
    std::cout << YELLOW << "Cat was born" << RESET << std::endl;
}

Cat::Cat(Cat const &autre) : Animal() {
    this->type = autre.type;
    brain = new Brain(*autre.brain); // deep copy
    std::cout << YELLOW << "Another Cat was born" << RESET << std::endl;
    return ;
}

Cat &Cat::operator=(Cat const &autre) {
    if (this != &autre) {
        delete this->brain;
        this->brain = new Brain(*autre.brain); // deep copy 
        this->type = autre.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << YELLOW << "Cat destructor called" << RESET << std::endl;
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << "\033[0;32mMiaou!\033[00m" << std::endl;
}

void	Cat::setIdeas(std::string str) {
	brain->setIdeas(str);
}

void Cat::printIdeas() const { 
    brain->printIdeas();
}

Brain	*Cat::getBrain() const {
	return (this->brain);
}