/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:52 by engo              #+#    #+#             */
/*   Updated: 2024/07/09 16:12:56 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define NB_ANIMALS 6

int main() {

    AAnimal *animal[NB_ANIMALS];
    // Animal a; // Classe abtraite, non instanciable

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

	std::cout << RED_B << "----------DESTRUCTORS----------" << RESET << std::endl;
    for (int j = 0; j < NB_ANIMALS; j++)
		delete animal[j];

	// std::cout << PINK_B << "----------DEEP COPY----------" << RESET << std::endl;

    // Dog dog1;
    // dog1.setIdeas("waf");
    // dog1.printIdeas();

    // Dog dog2(dog1);
    // dog2.printIdeas();
    // dog2.setIdeas("maiou");
    // dog1 = dog2;
    // dog1.printIdeas();

    // std::cout << "-------------------------" << std::endl;

    // Cat cat1;
    // cat1.setIdeas("waf");
    // cat1.printIdeas();

    // Cat cat2(cat1);
    // cat2.setIdeas("maiou");
    // cat2.printIdeas();
    // cat1 = cat2;
    // cat1.printIdeas();
    return 0;
}
