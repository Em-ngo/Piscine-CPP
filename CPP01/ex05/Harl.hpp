/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:07:55 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 19:11:23 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_PP

#include <string>
#include <iostream>

class Harl {

private :

    void debug(void);
    void info(void);
    void error(void);
    void warning(void);
    
public :

    Harl();
    ~Harl();
    void complain(std::string level); 
}

#endif