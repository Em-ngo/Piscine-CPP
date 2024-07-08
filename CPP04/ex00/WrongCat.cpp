/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:55:19 by engo              #+#    #+#             */
/*   Updated: 2024/07/03 16:14:06 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {

    this->type = "WrongCat";
    std::cout << "WrongCat was born" << std::endl;
} 

WrongCat::WrongCat(WrongCat const &autre) : WrongAnimal() {
    *this = autre;
    std::cout << "Another WrongCat was born" << std::endl;
    return;
}

WrongCat::~WrongCat() {
    std::cout << "Wrongcat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &autre) {
    this->type = autre.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << GREEN << "WrongCat said : [wrong cat noises]..\033[00m" << std::endl;
}
