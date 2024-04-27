/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:14:16 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 12:36:43 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie() {
    std::cout << name << " is dead.. " << std::endl;
}

void Zombie::setName(std::string NewName) {
    name = NewName;
}


void Zombie::announce() {
    std::cout << name << " : BraiiiiiiinnnzzzZ... " << std::endl;
}