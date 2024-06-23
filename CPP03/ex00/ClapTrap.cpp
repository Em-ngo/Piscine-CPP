/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:18:10 by engo              #+#    #+#             */
/*   Updated: 2024/06/23 17:31:08 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap named " << name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& autre) {
    this->name = autre.name;
    this->hitPoints = autre.hitPoints;
    this->energyPoints = autre.energyPoints;
    this->attackDamage = autre.attackDamage;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " have been destroyed !" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &autre) {
    if (this != &autre) {
        this->hitPoints = autre.hitPoints;
        this->energyPoints = autre.energyPoints;
        this->attackDamage = autre.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->hitPoints == 0 || this->energyPoints == 0)
        std::cout << "ClapTrap " << name << " can't attack because he has no HP or EP left!" << std::endl;
    else {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing \033[0;31m" << this->attackDamage << " points of damage !\033[00m" << std::endl;
        this->energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints < 1)
        std::cout << "ClapTrap " << name << " has no hitPoints left, he can't take any more damage !" << std::endl;
    std::cout << "ClapTrap " << name << " takes " << amount << " of damage !";
    this->hitPoints -= amount;
    std::cout << " He has \033[0;32m" << this->hitPoints << " HP\033[00m left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints == 0 || this->energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't be repaired because he has no HP or EP left!" << std::endl;
        return ;
    }
    if (this->hitPoints == 10) {
        std::cout << "ClapTrap " << name << " can't be repaired, he is already full health !" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " has been repaired for " << amount << " hit points!";
    this->hitPoints += amount;
    std::cout << " He now has \033[0;32m" << this->hitPoints << " HP!\033[00m" << std::endl;
    if (this->hitPoints > 10)
        this->hitPoints = 10;
}

