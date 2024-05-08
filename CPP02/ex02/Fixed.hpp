/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:09:56 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 14:49:59 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
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
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    float toInt() const;

    // Opérateurs de comparaison
    bool operator>(const Fixed& autre) const;
    bool operator<(const Fixed& autre) const;
    bool operator>=(const Fixed& autre) const;
    bool operator<=(const Fixed& autre) const;
    bool operator==(const Fixed& autre) const;
    bool operator!=(const Fixed& autre) const;

    // Opérateurs arithmétiques
    Fixed operator+(const Fixed& autre) const;
    Fixed operator-(const Fixed& autre) const;
    Fixed operator*(const Fixed& autre) const;
    Fixed operator/(const Fixed& autre) const;

    // Opérateurs d'incrémentation et de Fixed
    Fixed& operator++(); 
    Fixed operator++(int);
    Fixed& operator--(); 
    Fixed operator--(int); 

    // Fonctions membres statiques min et max

    static Fixed min(const Fixed& a, const Fixed& b);
    static const Fixed& min_ref(const Fixed& a, const Fixed& b);
    static Fixed max(const Fixed& a, const Fixed& b);
    static const Fixed& max_ref(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& nb);

#endif