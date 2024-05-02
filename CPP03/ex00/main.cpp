/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:40:17 by engo              #+#    #+#             */
/*   Updated: 2024/05/02 11:48:09 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

    ClapTrap Clap("Ed");

    std::cout << "----------------------------" << std::endl;
    Clap.attack("enemy");
    Clap.takeDamage(5);
    Clap.beRepaired(3);
    std::cout << "----------------------------" << std::endl;
    Clap.takeDamage(10);
    Clap.attack("enemy2");
    Clap.beRepaired(5);
    std::cout << "----------------------------" << std::endl;


    return 0;
}