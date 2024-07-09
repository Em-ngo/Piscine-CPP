/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:34:32 by engo              #+#    #+#             */
/*   Updated: 2024/07/09 22:36:28 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << PINK << "Brain's connected" << RESET << std::endl;
}

Brain::Brain(Brain const &autre) {
    std::cout << PINK << "Another brain's connected" << RESET << std::endl;
    for (int i = 0; i < 5; i++)
      ideas[i] = autre.ideas[i];
}

Brain &Brain::operator=(Brain const &autre) {
  if (this != &autre) {
    for (int i = 0; i < 5; i++)
      ideas[i] = autre.ideas[i];
  }
  return (*this);
}

void    Brain::setIdeas(std::string str) {
  for (int i = 0; i < 5; i++)
    ideas[i] = str;
}


Brain::~Brain() {
    std::cout << PINK << "Brain's disconnected" << RESET << std::endl;
}

void Brain::printIdeas() const {
    for (int i = 0; i < 5; ++i) {
        std::cout << ideas[i] << std::endl;
    }
}