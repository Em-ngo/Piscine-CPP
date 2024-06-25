/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:34:32 by engo              #+#    #+#             */
/*   Updated: 2024/06/25 15:28:02 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << PINK << "Brain's connected" << RESET << std::endl;
}

Brain::Brain(Brain const &autre) {
    std::cout << PINK << "Another brain's connected" << RESET << std::endl;
    *this = autre;
}

Brain &Brain::operator=(Brain const &autre) {
  int i = 0;
  while (i < 100) {
    this->ideas[i] = autre.ideas[i];
    i++;
  }
  return (*this);
}

Brain::~Brain() {
    std::cout << PINK << "Brain's disconnected" << RESET << std::endl;
}
