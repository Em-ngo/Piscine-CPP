/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:11:26 by engo              #+#    #+#             */
/*   Updated: 2024/07/09 15:06:06 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

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

class Dog : public Animal {

private:
    Brain* brain;

public:
    Dog();
    Dog(Dog const &src);
    virtual ~Dog();

    Dog &operator=(const Dog &autre);
    
    void makeSound() const;
    Brain *getBrain() const;
    void	setIdeas(std::string str);
    void     printIdeas() const;

};

#endif