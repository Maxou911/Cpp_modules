/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:18:38 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/09 13:25:25 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	std::cout << "=== Constructeurs ===" << std::endl;
	Fixed a;                          // Default
	Fixed b(10);                      // Int
	Fixed c(42.42f);                  // Float
	Fixed d(b);                       // Copy constructor

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "\n=== Conversion ===" << std::endl;
	std::cout << "c en int = " << c.toInt() << std::endl;
	std::cout << "c en float = " << c.toFloat() << std::endl;

	std::cout << "\n=== Comparaisons ===" << std::endl;
	std::cout << "b > c --> " << (b > c) << std::endl;
	std::cout << "b < c --> " << (b < c) << std::endl;
	std::cout << "b == d --> " << (b == d) << std::endl;
	std::cout << "b != c --> " << (b != c) << std::endl;
	std::cout << "c >= b --> " << (c >= b) << std::endl;
	std::cout << "a <= b --> " << (a <= b) << std::endl;

	std::cout << "\n=== Arithmetiques ===" << std::endl;
	Fixed e = b + c;
	Fixed f = c - b;
	Fixed g = b * 2;
	Fixed h = c / Fixed(2);

	std::cout << "b + c = " << e << std::endl;
	std::cout << "c - b = " << f << std::endl;
	std::cout << "b * 2 = " << g << std::endl;
	std::cout << "c / 2 = " << h << std::endl;

	std::cout << "\n=== Incrementation / Decrementation ===" << std::endl;
	Fixed x;
	std::cout << "x   = " << x << std::endl;
	std::cout << "++x = " << ++x << std::endl; // Pre-incr
	std::cout << "x   = " << x << std::endl;
	std::cout << "x++ = " << x++ << std::endl; // Post-incr
	std::cout << "x   = " << x << std::endl;
	std::cout << "--x = " << --x << std::endl; // Pre-incr
	std::cout << "x-- = " << x-- << std::endl; // Post-incr
	std::cout << "x   = " << x << std::endl;

	std::cout << "\n=== Min / Max ===" << std::endl;
	Fixed y(5.05f * 2); // 10.1
	std::cout << "y = " << y << std::endl;
	std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl;
	std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;

	return (0);
}
