/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:39 by engo              #+#    #+#             */
/*   Updated: 2024/07/09 23:14:29 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
    type = "Animal";
    std::cout << L_BLUE << "Animal was born" << RESET << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << BLUE << "Animal destructor called" << RESET << std::endl;
}

AAnimal::AAnimal(AAnimal const &autre) {
    *this = autre;
    return ;
}

std::string const	AAnimal::getType() const {
	return (this->type);
}


AAnimal &AAnimal::operator=(const AAnimal &autre) {
    if (this != &autre)
        this->type = autre.type;
    return *this;
}