/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:12:21 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 14:42:49 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
# include <iostream>
# include <cstdlib>
# include <string>

class Zombie {
    
private:

    std::string name;

public:

    Zombie(std::string ZombieName);
    Zombie();
    ~Zombie();
    void announce();
    void setName(std::string NewName);
};

Zombie* ZombieHorde(int N, std::string name);


#endif

