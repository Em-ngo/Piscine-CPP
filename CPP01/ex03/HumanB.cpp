/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:44:36 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 16:16:20 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string input) {
    name = input;
    this->m_weapon = NULL;
}

void    HumanB::attack() {
    std::string input = m_weapon->getType();
    if (this->m_weapon == NULL)
        std::cout << name << " do not have a weapon, he can't attack." << std::endl;
    else
        std::cout << name << " attacks with their " << input << std::endl;
}

void    HumanB::setWeapon(Weapon &input) {
    this->m_weapon = &input;
}

HumanB::~HumanB() {
}

