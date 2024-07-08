/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:13:52 by engo              #+#    #+#             */
/*   Updated: 2024/07/03 16:14:24 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

    std::cout << "\033[0;34m Animal class \033[00m" << std::endl;
    Animal* animal = new Animal();
    std::cout << animal->getType() << std::endl;
    animal->makeSound();

    std::cout << "\n";
    std::cout << "\033[0;34m Cat class \033[00m" << std::endl;
    Animal* cat = new Cat();
    std::cout << cat->getType() << std::endl;
    cat->makeSound();

    std::cout << "\n";
    std::cout << "\033[0;34m Dog class \033[00m" << std::endl;
    Animal* dog = new Dog();
    std::cout << dog->getType() << std::endl;
    dog->makeSound();

    std::cout << "\n";
    std::cout << "\033[0;34m WrongAnimal class \033[00m" << std::endl;
    WrongAnimal* wrongAnimal = new WrongAnimal();
    std::cout << wrongAnimal->getType() << std::endl;
    wrongAnimal->makeSound();

    std::cout << "\n";
    std::cout << "\033[0;34m WrongCat class \033[00m" << std::endl;
    WrongAnimal* wrongCat = new  WrongCat();
    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound();

    std::cout << "\n";
    std::cout << "\033[0;31m Destructors \033[00m" << std::endl;
    delete animal;
    delete cat;
    delete dog;
    delete wrongAnimal;
    delete wrongCat;
    return 0;
}