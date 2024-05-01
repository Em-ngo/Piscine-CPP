/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:52:55 by engo              #+#    #+#             */
/*   Updated: 2024/05/01 10:50:17 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const a) {
    std::cout << "Int constructor called" << std::endl;
    value = a << bitsFractionnaires;
}

Fixed::Fixed(float const nb) {
    std::cout << "Float constructor called" << std::endl;
    value = (int)roundf(nb * (1 << bitsFractionnaires));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &autre) {
    std::cout << "Copy constructor called" << std::endl;
    Fixed::value = autre.getRawBits();
}

Fixed& Fixed::operator=(Fixed const &autre) {
    std::cout << "Copy assignement operator called\n";
    this->value = autre.getRawBits();
    return *this;

}

int Fixed::getRawBits() const {
    return (value);
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(value) / (1 << bitsFractionnaires);
}

float Fixed::toInt() const {
    return (value >> bitsFractionnaires);
}

std::ostream& operator<<(std::ostream& os, const Fixed& nb) {
    os << nb.toFloat();
    return (os);
}
