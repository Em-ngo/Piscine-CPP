/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:41:18 by engo              #+#    #+#             */
/*   Updated: 2024/04/28 13:41:52 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl input;
    input.complain("DEBUG");
    std::cout << std::endl;
    input.complain("INFO");
    std::cout << std::endl;
    input.complain("ERROR");
    std::cout << std::endl;
    input.complain("WARNING");
    std::cout << std::endl;
    input.complain("");
    
    return 0;
}