/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operateur_Compare.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:47:15 by maalwis           #+#    #+#             */
/*   Updated: 2025/10/02 14:56:51 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool Fixed::operator>(const Fixed &a) const
{
	return (this->_value > a._value);
}
bool Fixed::operator<(const Fixed &a) const
{
	return (this->_value < a._value);
}
bool Fixed::operator>=(const Fixed &a) const
{
	return (this->_value >= a._value);
}
bool Fixed::operator<=(const Fixed &a) const
{
	return (this->_value <= a._value);
}
bool Fixed::operator==(const Fixed &a) const
{
	return (this->_value == a._value);
}
bool Fixed::operator!=(const Fixed &a) const
{
	return (this->_value != a._value);
}