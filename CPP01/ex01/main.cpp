/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:29:43 by engo              #+#    #+#             */
/*   Updated: 2024/06/19 19:31:52 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int main(int ac, char **av) {
    
    int n_Zombie = -1;
    std::string name = "Foo";
    Zombie *horde;
    int i = 0;
    
    std::cout << "\033[0;34mZombie Horde being created \033[00m" << std::endl;
    if(ac == 1 || atoi(av[1]) <= 0)
        n_Zombie = 10;
    else
        n_Zombie = atoi(av[1]);
    if (ac >= 3)
        name = av[2];

    horde = ZombieHorde(n_Zombie, name);
    
    while (i < n_Zombie) {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return 0;
}