/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:06:17 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 12:06:06 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string ZombieName) : name(ZombieName) {
    std::cout << name << " is alive !" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " is dead.. " << std::endl;
}

void Zombie::announce() {
    std::cout << name << " : BraiiiiiiinnnzzzZ... " << std::endl;
}
