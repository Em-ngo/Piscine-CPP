/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:52 by engo              #+#    #+#             */
/*   Updated: 2024/07/03 11:25:50 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define NB_ANIMALS 6

int main() {

    Animal *animal[NB_ANIMALS];
    Brain *brain;

    int i = 0;
    while (i < NB_ANIMALS) {
        if (i % 2 == 0) {
            animal[i] = new Dog();
        }
        else {
            animal[i] = new Cat();
        }
        std::cout << "Animal [" << BLUE << i << RESET << "] has been created with " << animal[i]->getType() << std::endl;
        std::cout << WHITE << "-----------------------------------" << RESET << std::endl;
        i++;
    }

    std::cout << SKY << "Animal[2] brain's ideas" << RESET << std::endl;
    brain = animal[2]->getBrain();
	brain->ideas[0] = "Ideas 1 😽";
	brain->ideas[1] = "Ideas 2 🙀";
	brain->ideas[2] = "Ideas 3 😾";
	brain->ideas[3] = "Ideas 4 😻";
	std::cout << animal[2]->getBrain()->ideas[0] << std::endl;
	std::cout << animal[2]->getBrain()->ideas[1] << std::endl;
	std::cout << animal[2]->getBrain()->ideas[2] << std::endl;
	std::cout << animal[2]->getBrain()->ideas[3] << std::endl;

	std::cout << WHITE_B << "----------DEEP COPY----------" << RESET << std::endl;
    Cat b; {
        Cat c(b);
    }

	std::cout << RED_B << "----------DESTRUCTORS----------" << RESET << std::endl;
    for (int j = 0; j < NB_ANIMALS; j++)
		delete animal[j];
    return 0;
}
