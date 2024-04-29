/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:41:18 by engo              #+#    #+#             */
/*   Updated: 2024/04/29 11:25:42 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl input;
    input.complain("debug");
    std::cout << std::endl;
    input.complain("info");
    std::cout << std::endl;
    input.complain("error");
    std::cout << std::endl;
    input.complain("warning");
    std::cout << std::endl;
    input.complain("");
    
    return 0;
}