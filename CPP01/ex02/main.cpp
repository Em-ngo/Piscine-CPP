/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:08:20 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 15:16:12 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "\033[0;95m----CONTENT OF THE STRING----\033[00m" << std::endl;
    
    std::cout << "\033[0;32m   Str :   \033[00m" << str << std::endl;
    std::cout << "\033[0;32m   stringPTR :   \033[00m" << *stringPTR << std::endl;
    std::cout << "\033[0;32m   stringREF  :   \033[00m" << stringREF << std::endl;
    
    std::cout << "\n" << std::endl;
    
    std::cout << "\033[0;95m----ADDRESS OF THE STRING----\033[00m" << std::endl;
    
    std::cout << "\033[0;32m   Str :   \033[00m" << &str << std::endl;
    std::cout << "\033[0;32m   stringPTR :   \033[00m" << stringPTR << std::endl;
    std::cout << "\033[0;32m   stringREF  :   \033[00m" << &stringREF << std::endl;
}