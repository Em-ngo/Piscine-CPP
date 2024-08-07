/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:00 by engo              #+#    #+#             */
/*   Updated: 2024/07/09 23:06:30 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << GREEN << "Dog was born" << RESET << std::endl;
}

Dog::Dog(Dog const &autre) : AAnimal() {
    this->type = autre.type;
    std::cout << GREEN << "Another Dog was born" << RESET << std::endl;
    this->brain = new Brain(*autre.brain); // deep copy;
    return ;
}

Dog &Dog::operator=(Dog const &autre) {
    if (this != &autre) {
        delete this->brain;
        this->brain = new Brain(*autre.brain); // deep copy
        this->type = autre.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << GREEN << "Dog destructor called" << RESET << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << "\033[0;32mWoof Woof!\033[00m" << std::endl;
}

Brain	*Dog::getBrain() const {
	return (this->brain);
}

void Dog::printIdeas() const { 
    brain->printIdeas();
}

void	Dog::setIdeas(std::string str)
{
	brain->setIdeas(str);
}
