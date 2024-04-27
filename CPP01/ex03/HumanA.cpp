/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:26:20 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 15:43:56 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string input, Weapon &weapon) : name(input), m_weapon(weapon) {
}

void    HumanA::attack() {
    std::cout << name << " attacks with their " << this->m_weapon.getType() << std::endl;
}

HumanA::~HumanA() {
}
