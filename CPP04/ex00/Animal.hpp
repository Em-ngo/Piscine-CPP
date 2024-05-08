/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:03 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 16:23:56 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    
protected:

    std::string type;

public:
    Animal();
    Animal(Animal const &autre);
    virtual ~Animal();
    
    std::string const		getType() const;
    virtual void makeSound() const;
    
    Animal &operator=(const Animal &autre);
    

};

#endif 