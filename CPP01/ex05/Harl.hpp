/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:07:55 by engo              #+#    #+#             */
/*   Updated: 2024/04/29 11:16:23 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

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
};

typedef void (Harl::*PtrFnct)(void);

#endif