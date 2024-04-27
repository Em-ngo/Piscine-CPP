/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:21:12 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 16:32:50 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
  
private :

    std::string type;

public :

    Weapon(std::string input);
    ~Weapon();
    const std::string &getType();
    void    setType(std::string input);
    
};

#endif