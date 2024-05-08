/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:06:58 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 15:58:10 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    
public :
        
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const &autre);
    ~FragTrap();

    void highFivesGuys(void);
    void attack(const std::string& target);
    FragTrap &operator=(const FragTrap &autre);
};


#endif