/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:56:03 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 16:03:10 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string input) {
    setType(input);
}

std::string &Weapon::getType() {
    return (this->type);
}

void    Weapon::setType(std::string input) {
    this->type = input;
}

Weapon::~Weapon() {
}