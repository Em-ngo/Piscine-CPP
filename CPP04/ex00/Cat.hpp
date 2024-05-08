/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:11:26 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 16:45:57 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

public:
    Cat();
    Cat(Cat const &autre);
    virtual ~Cat();

    Cat &operator=(Cat const &autre);
    
    void makeSound() const;
};

#endif