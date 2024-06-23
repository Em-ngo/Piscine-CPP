/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:40:17 by engo              #+#    #+#             */
/*   Updated: 2024/06/23 17:21:02 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

    // Nouvelle classe
    std::cout << "\033[0;34mCreating a ClapTrap\033[00m" << std::endl;
    std::cout << "----------------------------" << std::endl;
    ClapTrap Clap("Warrior");
    Clap.attack("enemy"); // 0
    Clap.takeDamage(5); // 5
    Clap.beRepaired(3); // 8
    std::cout << "\n";

    // Nouvelle classe 
    std::cout << "\033[0;34mCreating a ClapTrap\033[00m" << std::endl;
    std::cout << "----------------------------" << std::endl;
    ClapTrap trap("Mage");
    trap.takeDamage(0); // 0
    trap.attack("enemy2"); // 0
    trap.beRepaired(10); // 10
    std::cout << "\n";
    
    // Nouvelle classe
    std::cout << "\033[0;34mCreating a ClapTrap\033[00m" << std::endl;
    std::cout << "----------------------------" << std::endl;
    ClapTrap claptrap("Paladin");
    claptrap.takeDamage(10); // 0
    claptrap.attack("enemy2"); // 0
    claptrap.beRepaired(10); // 0

    // Destructeur 
    std::cout << "\n";
    std::cout << "\033[0;31mDestroying ClapTraps\033[00m" << std::endl;
    std::cout << "----------------------------" << std::endl;


    return 0;
}