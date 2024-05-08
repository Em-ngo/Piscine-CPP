/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:11:37 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 15:57:40 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap() {
    this->energyPoints = 100;
    this->attackDamage = 30;
    return ;
}

FragTrap::FragTrap(FragTrap const &autre) : ClapTrap(name) {
    this->energyPoints = 100;
    this->attackDamage = 30;
    *this = autre;
    return ;
}

FragTrap& FragTrap::operator=(const FragTrap &autre) {
	this->name = autre.name;
	this->hitPoints = autre.hitPoints;
	this->energyPoints = autre.energyPoints;
	this->attackDamage = autre.attackDamage;
	return (*this);
}

void FragTrap::attack(const std::string& target) {
    if (this->hitPoints == 0 || this->energyPoints == 0) {
        std::cout << "FragTrap " << this->name << " can't attack because he has no HP or EP left!" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage !" << std::endl;
    this->energyPoints--;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap named " << name << " is born!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " has been destroyed !" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->name << " is requesting a fist bump !" << std::endl;
}