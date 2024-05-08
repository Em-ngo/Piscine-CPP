/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:14:38 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 14:14:42 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    
    std::cout << "\033[0;34mCreating Foo on the heap :\033[00m" << std::endl;
    Zombie* myZombie = NewZombie("Foo");
    myZombie->announce();
    delete myZombie;
    std::cout << "\n\033[0;34mCreating Steve on the stack :\033[00m" << std::endl;
    RandomChump("Steve");
    return 0;
}