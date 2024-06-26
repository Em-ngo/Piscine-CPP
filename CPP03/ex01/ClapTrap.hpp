/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:13:26 by engo              #+#    #+#             */
/*   Updated: 2024/06/23 17:33:54 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>


class ClapTrap {

protected : 

    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
    
public :

    ClapTrap(); 
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &autre);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    ClapTrap &operator=(ClapTrap const &autre);

};

#endif