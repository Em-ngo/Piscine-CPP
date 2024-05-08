/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:18:10 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 15:25:38 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(100), energyPoints(100), attackDamage(30) {
    
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(100), energyPoints(100), attackDamage(30) {
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
        this->name = autre.name;
        this->hitPoints = autre.hitPoints;
        this->energyPoints = autre.energyPoints;
        this->attackDamage = autre.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->hitPoints == 0 || this->energyPoints == 0)
        std::cout << "ClapTrap " << this->name << " can't attack because he has no HP or EP left!" << std::endl;
    else {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage !" << std::endl;
        this->energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints < 1)
        std::cout << "ClapTrap " << this->name << " has no hitPoints left, he can't take any more damage !" << std::endl;
    std::cout << "ClapTrap " << this->name << " takes " << amount << " of damage !";
    this->hitPoints -= amount;
    std::cout << " He has " << this->hitPoints << " HP left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints == 0 || this->energyPoints == 0) {
        std::cout << "ClapTrap " << this->name << " can't be repaired because he has no HP or EP left!" << std::endl;
        return ;
    }
    if (this->hitPoints == 10) {
        std::cout << "ClapTrap " << this->name << " can't be repaired, he is already full health !" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " has been repaired for " << amount << " hit points!";
    this->hitPoints += amount;
    std::cout << " He now has " << this->hitPoints << " HP!" << std::endl;
    if (this->hitPoints > 100)
        this->hitPoints = 100;
}

