/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:10:56 by engo              #+#    #+#             */
/*   Updated: 2024/04/28 13:45:21 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::info(void) {
    std::cout << "[INFO] : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[WARNING] : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::debug(void) {
    std::cout << "[DEBUG] : I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do !" << std::endl;
}

void Harl::error(void) {
    std::cout << "[ERROR] : This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    
    std::string str[] = {"DEBUG", "INFO", "ERROR", "WARNING"};
    PtrFnct tab[] = {&Harl::debug, &Harl::info, &Harl::error, &Harl::warning};

    int i = 0;
    while(level != str[i]) {
        i++;
        if (i > 3) {
            std::cout << "Error : invalid input" << std::endl;
            return ;
        }
    }
    (this->*tab[i])();
}