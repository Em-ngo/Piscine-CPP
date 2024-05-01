/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:52:55 by engo              #+#    #+#             */
/*   Updated: 2024/05/01 11:34:20 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
}

Fixed::Fixed(int const a) {
    value = a << bitsFractionnaires;
}

Fixed::Fixed(float const nb) {
    value = (int)roundf(nb * (1 << bitsFractionnaires));
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed &autre) {
    Fixed::value = autre.getRawBits();
}

Fixed& Fixed::operator=(Fixed const &autre) {
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

bool Fixed::operator>(const Fixed& autre) const {
    return value > autre.value;
}

bool Fixed::operator<(const Fixed& autre) const {
    return value < autre.value;
}

bool Fixed::operator>=(const Fixed& autre) const {
    return value >= autre.value;
}

bool Fixed::operator<=(const Fixed& autre) const {
    return value <= autre.value;
}

bool Fixed::operator==(const Fixed& autre) const {
    return value == autre.value;
}

bool Fixed::operator!=(const Fixed& autre) const {
    return value != autre.value;
}

Fixed Fixed::operator+(const Fixed& autre) const {
    return Fixed(value + autre.value);
}

Fixed Fixed::operator-(const Fixed& autre) const {
    return Fixed(value - autre.value);
}

Fixed Fixed::operator*(const Fixed& autre) const {
    Fixed res(this->toFloat() * autre.toFloat());
    return res;
}

Fixed Fixed::operator/(const Fixed& autre) const {
    return Fixed((value << bitsFractionnaires) / autre.value);
}

Fixed& Fixed::operator++() {
    value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min_ref(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max_ref(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}