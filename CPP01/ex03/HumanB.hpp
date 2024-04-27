/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:26:11 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 16:08:11 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB {
    
private:
    std::string name;
    Weapon *m_weapon;
    
public :

        HumanB(std::string input);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &input);
};


#endif