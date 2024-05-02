/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:18:10 by engo              #+#    #+#             */
/*   Updated: 2024/05/02 12:03:22 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (hitPoints == 0 || energyPoints == 0) {
            std::cout << "ClapTrap " << name << " can't attack because he has no hit points or energy points left!" << std::endl;
            return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " has no hit points left and can't take any more damage!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints == 0 || energyPoints == 0) {
            std::cout << "ClapTrap " << name << " has no hit points or energy points left to be repaired!" << std::endl;
            return;
    }

    std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
    hitPoints += amount;
    if (hitPoints > 10)
        hitPoints = 10;
    energyPoints--;
}

