/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:09:56 by engo              #+#    #+#             */
/*   Updated: 2024/05/01 10:27:30 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {

private :

    int value;
    static const int bitsFractionnaires = 8;

public:

    Fixed();
    Fixed(int const a);
    Fixed(float const nb);
    Fixed(const Fixed &autre);
    Fixed &operator=(const Fixed &autre);
    std::ostream& insererDansFlux(std::ostream& os) const;
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    float toInt() const;
    
};

std::ostream& operator<<(std::ostream& os, const Fixed& nb);

#endif