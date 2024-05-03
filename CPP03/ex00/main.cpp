/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:40:17 by engo              #+#    #+#             */
/*   Updated: 2024/05/03 11:24:02 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

    // Nouvelle classe
    std::cout << "\033[0;34mCreating a ClapTrap\033[00m" << std::endl;
    std::cout << "----------------------------" << std::endl;
    ClapTrap Clap("Warrior");
    Clap.attack("enemy");
    Clap.takeDamage(5);
    Clap.beRepaired(3);
    std::cout << "\n";

    // Nouvelle classe 
    std::cout << "\033[0;34mCreating a ClapTrap\033[00m" << std::endl;
    std::cout << "----------------------------" << std::endl;
    ClapTrap trap("Mage");
    trap.takeDamage(0);
    trap.attack("enemy2");
    trap.beRepaired(10);
    std::cout << "\n";
    
    // Nouvelle classe
    std::cout << "\033[0;34mCreating a ClapTrap\033[00m" << std::endl;
    std::cout << "----------------------------" << std::endl;
    ClapTrap claptrap("Paladin");
    claptrap.takeDamage(10);
    claptrap.attack("enemy2");
    claptrap.beRepaired(10);

    // Destructeur 
    std::cout << "\n";
    std::cout << "\033[0;31mDestroying ClapTraps\033[00m" << std::endl;
    std::cout << "----------------------------" << std::endl;


    return 0;
}