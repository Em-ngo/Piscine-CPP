/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:08:07 by engo              #+#    #+#             */
/*   Updated: 2024/05/02 16:08:08 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Test construction of ClapTrap
    std::cout << "Creating a ClapTrap:" << std::endl;
    ClapTrap clap("CL4P-TP");
    clap.attack("Jack");
    clap.takeDamage(10);
    clap.beRepaired(5);

    // Test construction of ScavTrap
    std::cout << "\nCreating a ScavTrap:" << std::endl;
    ScavTrap scav("SC4V-TP");
    scav.attack("Handsome Jack");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    // Automatic destruction of ClapTrap and ScavTrap at the end of scope
    std::cout << "\nDestruction order:" << std::endl;
    return 0;
}