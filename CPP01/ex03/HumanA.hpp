/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:27:52 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 15:38:29 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA {
    
private:
    const std::string name;
    Weapon &m_weapon;

public :

        HumanA(std::string input, Weapon&weapon);
        ~HumanA();
        void attack();
};


#endif