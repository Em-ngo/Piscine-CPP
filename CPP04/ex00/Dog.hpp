/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:11:26 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 16:28:50 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

public:
    Dog();
    Dog(Dog const &src);
    virtual ~Dog();

    Dog &operator=(const Dog &autre);
    
    void makeSound() const;
};

#endif