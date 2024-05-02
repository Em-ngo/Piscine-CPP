/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:05:25 by engo              #+#    #+#             */
/*   Updated: 2024/05/02 16:18:42 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;  
    this->energyPoints = 50; 
    this->attackDamage = 20; 
    std::cout << "ScavTrap " << this->name << " is created as a new guardian!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " is being destroyed and has left the gate!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints <= 0 || hitPoints <= 0) {
        std::cout << "ScavTrap " << name << " can't attack because it has no hit points or energy points left!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ScavTrap " << name << " has no hit points left and can't take any more damage!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    hitPoints -= amount;
    if (hitPoints < 0) 
        hitPoints = 0;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ScavTrap " << name << " has no hit points or energy points left to be repaired!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
    hitPoints += amount;
    if (hitPoints > 100) 
        hitPoints = 100;
    energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gatekeeper mode." << std::endl;
}
