/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:31:03 by engo              #+#    #+#             */
/*   Updated: 2024/07/09 15:12:27 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

# define DEFAULT	"\033[0;39m"
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define RED_B		"\033[1;31m"
# define L_RED		"\033[0;91m"
# define GREEN		"\033[0;32m"
# define GREEN_B	"\033[1;32m"
# define L_GREEN	"\033[0;92m"
# define YELLOW		"\033[0;33m"
# define L_YELLOW	"\033[0;93m"
# define YELLOW_B	"\033[1;33m"
# define BLUE		"\033[0;34m"
# define BLUE_B		"\033[1;34m"
# define L_BLUE		"\033[0;94m"
# define PINK		"\033[0;35m"
# define L_PINK		"\033[0;95m"
# define PINK_B		"\033[1;95m"
# define SKY		"\033[0;36m"
# define SKY_B		"\033[1;36m"
# define L_CYAN		"\033[0;96m"
# define GREY		"\033[0;37m"
# define D_GREY		"\033[0;90m"
# define WHITE		"\033[0;97m"
# define WHITE_B	"\033[1;97m"
# define RESET		"\e[0m"

class Brain  {

public :
    Brain();
    Brain(Brain const &autre);
    ~Brain();

    std::string ideas[100];
    
    Brain &operator=(Brain const &autre);
    void    setIdeas(std::string str);
    void    printIdeas() const;

};

#endif