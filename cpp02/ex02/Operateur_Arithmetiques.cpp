/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operateur_Arithmetiques.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:46:06 by maalwis           #+#    #+#             */
/*   Updated: 2025/10/02 13:04:17 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	long tmp = this->_value / other._value;
	result._value = tmp >> _fractionalBits;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long tmp = this->_value * other._value;
	result._value = tmp >> _fractionalBits;
	return (result);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	long tmp = this->_value + other._value;
	result._value = tmp >> _fractionalBits;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	long tmp = this->_value - other._value;
	result._value = tmp >> _fractionalBits;
	return (result);
}