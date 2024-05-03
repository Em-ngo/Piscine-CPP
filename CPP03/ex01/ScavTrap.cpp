/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:32:35 by engo              #+#    #+#             */
/*   Updated: 2024/05/03 12:37:54 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const &autre) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->name = name;
    *this = autre;
    return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap named " << name << " is born!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " has been destroyed !" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &autre) {
	this->name = autre.name;
	this->hitPoints = autre.hitPoints;
	this->energyPoints = autre.energyPoints;
	this->attackDamage = autre.attackDamage;
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
    if (this->hitPoints == 0 || this->energyPoints == 0) {
        std::cout << "ScavTrap " << this->name << " can't attack because he has no HP or EP left!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage !" << std::endl;
    this->energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in GateKeeper mode!" << std::endl;
}