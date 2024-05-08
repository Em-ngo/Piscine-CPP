/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:40:17 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 16:00:08 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    // ClapTrap //
    std::cout << "\033[0;32m-- Constructing ClapTrap --\033[00m" << std::endl;
    ClapTrap claptrap("Mage");
    claptrap.takeDamage(50);
    claptrap.attack("enemy2");
    claptrap.beRepaired(10);
    std::cout << "\n";

    // ScavTrap //
    std::cout << "\033[0;32m-- Constructing ScavTrap --\033[00m" << std::endl;
    ScavTrap scavtrap("Paladin");
    scavtrap.takeDamage(10);
    scavtrap.attack("enemy2");
    scavtrap.beRepaired(10);
    std::cout << "\033[0;34m-- Using ScavTrap's special ability --\033[00m" << std::endl;
    scavtrap.guardGate();
    std::cout << "\n";

    // FragTrap //
    std::cout << "\033[0;32m-- Constructing FragTrap --\033[00m" << std::endl;
    FragTrap fragtrap("Warrior");
    fragtrap.takeDamage(40);
    fragtrap.attack("enemy2");
    fragtrap.beRepaired(30);
    std::cout << "\033[0;34m-- Using fragtrap's special ability --\033[00m" << std::endl;
    fragtrap.highFivesGuys();
    

    // Destructeurs //
    std::cout << "\n";
    std::cout << "\033[0;31m-- Destructing FragTrap --\033[00m" << std::endl;
    std::cout << "\033[0;31m-- Destructing ScavTrap --\033[00m" << std::endl;
    std::cout << "\033[0;31m-- Destructing ClapTrap --\033[00m" << std::endl;
    return 0;
}