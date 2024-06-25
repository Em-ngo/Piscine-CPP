/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:52 by engo              #+#    #+#             */
/*   Updated: 2024/06/25 15:33:32 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define NB_ANIMALS 10

int main() {

    Animal *animal[NB_ANIMALS];

    int i = 0;
    while (i < NB_ANIMALS) {
        if (i % 2 == 0) {
            animal[i] = new Dog();
        }
        else {
            animal[i] = new Cat();
        }
        std::cout << "Animal [" << BLUE << i << RESET << "] has been created with " << animal[i]->getType() << std::endl;
        std::cout << RED_B << "-----------------------------------" << RESET << std::endl;
        i++;
    }
    int j = NB_ANIMALS;

    while (j >= 0) {
       delete animal[j];
       j--;
    }
    return 0;
}
