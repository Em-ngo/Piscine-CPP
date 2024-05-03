/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:29:44 by engo              #+#    #+#             */
/*   Updated: 2024/05/03 12:38:10 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public :

    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &autre);
    ~ScavTrap();
    
    void guardGate();
    void attack(const std::string& target);
    ScavTrap &operator=(const ScavTrap &autre);


};

#endif