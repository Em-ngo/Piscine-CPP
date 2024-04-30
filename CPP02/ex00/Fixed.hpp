/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:09:56 by engo              #+#    #+#             */
/*   Updated: 2024/04/30 14:31:46 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed {

private :

    int value;
    static const int bitsFractionnaires = 8;

public:

    Fixed();
    ~Fixed();
    Fixed(const Fixed &autre);
    Fixed &operator=(const Fixed &autre);

    int getRawBits() const;
    void setRawBits(int const raw);
    
};

#endif