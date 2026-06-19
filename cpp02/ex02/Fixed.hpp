/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:18:48 by maalwis           #+#    #+#             */
/*   Updated: 2025/10/02 13:40:08 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &copy);
		~Fixed();

		// Operateur d'affectation
		Fixed &operator=(const Fixed &copy);

		// Operateurs de comparaison
		bool operator>(const Fixed &a) const;
		bool operator<(const Fixed &a) const;
		bool operator>=(const Fixed &a) const;
		bool operator<=(const Fixed &a) const;
		bool operator==(const Fixed &a) const;
		bool operator!=(const Fixed &a) const;
		
		// Operateurs arithmetiques
		Fixed operator*(const Fixed &a) const;
		Fixed operator+(const Fixed &a) const;
		Fixed operator-(const Fixed &a) const;
		Fixed operator/(const Fixed &a) const;
		
		// Operateurs d'incrementation
		Fixed &operator++(); // Prefix
		Fixed operator++(int); // Postfix

		// Operateurs de decrementation
		Fixed &operator--(); // Prefix
		Fixed operator--(int); // Postfix

		// Fonctions surchargees
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream &operator << (std::ostream&, const Fixed &o);

#endif