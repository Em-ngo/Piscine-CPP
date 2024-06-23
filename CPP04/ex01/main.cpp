/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:52 by engo              #+#    #+#             */
/*   Updated: 2024/06/23 21:59:16 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

    std::cout << BLUE << "-----Animal class-----" << RESET << std::endl;
    Animal* animal = new Animal();
    std::cout << animal->getType() << std::endl;
    animal->makeSound();

    std::cout << "\n";
    std::cout << BLUE << "-----Cat class-----" << RESET << std::endl;
    Animal* cat = new Cat();
    std::cout << cat->getType() << std::endl;
    cat->makeSound();

    std::cout << "\n";
    std::cout << BLUE << "-----Dog class-----" << RESET << std::endl;
    Animal* dog = new Dog();
    std::cout << dog->getType() << std::endl;
    dog->makeSound();

    std::cout << "\n";
    std::cout << BLUE << "-----WrongAnimal class-----" << RESET << std::endl;
    WrongAnimal* wrongAnimal = new WrongAnimal();
    std::cout << wrongAnimal->getType() << std::endl;
    wrongAnimal->makeSound();

    std::cout << "\n";
    std::cout << BLUE << "----WrongCat class-----" << RESET <<  std::endl;
    WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound();

    std::cout << "\n";
    std::cout << RED << "-----Destructors-----" << RESET << std::endl;
    delete animal;
    delete cat;
    delete dog;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}