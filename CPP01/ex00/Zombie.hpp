/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:59:21 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 14:14:19 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie {
    
private:

    std::string name;

public:

    Zombie(std::string ZombieName);
    ~Zombie();
    void announce();
    
};


void RandomChump(std::string name); 
Zombie* NewZombie(std::string name);

#endif