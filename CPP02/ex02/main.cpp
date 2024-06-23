/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:11:12 by engo              #+#    #+#             */
/*   Updated: 2024/06/23 16:13:46 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	std::cout << "\n\033[0;32mSubject main\033[00m\n";
	std::cout << "-----------------\n";
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl; // 0
	std::cout << ++a << std::endl; // 0.00390625
	std::cout << a << std::endl; // 0.00390625
	std::cout << a++ << std::endl; // 0.00390625
	std::cout << a << std::endl; // 0.0078125
	std::cout << b << std::endl; // 10.1016
	std::cout << Fixed::max(a, b) << std::endl; // 10.1016

	std::cout << "\n\033[0;32mMy main\033[00m\n";
	std::cout << "-----------------\n";
	Fixed c = a;
	std::cout << Fixed::min(c, b) << std::endl; // 0.0078125
	std::cout << b / Fixed(2) << std::endl; // 5.05078
	std::cout << b + Fixed(-3.14f) << std::endl; // 6.96094
	std::cout << b - Fixed(18) << std::endl; // -7.89844
	std::cout << (c != a) << std::endl; // 0
	std::cout << (c == a) << std::endl; // 1
	return 0; 
}
