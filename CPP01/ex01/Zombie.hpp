/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:12:21 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 13:05:50 by engo             ###   ########.fr       */
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
    void getName(std::string NewName);
};

Zombie* zombieHorde(int N, std::string name);


#endif

