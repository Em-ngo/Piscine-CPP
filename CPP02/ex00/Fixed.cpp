/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:52:55 by engo              #+#    #+#             */
/*   Updated: 2024/04/30 14:35:35 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &autre) : value(autre.value) {
    std::cout << "Copy constructor called" << std::endl;
    Fixed::value = autre.getRawBits();
}

Fixed& Fixed::operator=(Fixed const &autre) {
    std::cout << "Copy assignement operator called\n";
    this->value = autre.getRawBits();
    return *this;

}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

