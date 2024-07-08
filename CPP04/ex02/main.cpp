/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:52 by engo              #+#    #+#             */
/*   Updated: 2024/07/08 14:58:19 by engo             ###   ########.fr       */
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

    // Animal a; //Classe abstraite, non instanciable

    std::cout << "-----Creating Cat Class------" << std::endl;
    Cat b; {
        Cat c(b);
    }
    std::cout << "\n";
    std::cout << "-----Creating Dog Class------" << std::endl;
    Dog g;

    std::cout << "\n";
    std::cout << RED << "-----Destructors------" << RESET << std::endl;
    
    return 0;
}
