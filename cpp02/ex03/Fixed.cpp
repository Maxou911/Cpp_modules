/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:18:58 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/04 14:15:20 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(int n)
{
	this->_value = n << _fractionalBits;
}

Fixed::Fixed(float f)
{
	this->_value = roundf(f * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

float Fixed::toFloat( void ) const
{
	return (this->_value / (float)(1 << _fractionalBits));
}

std::ostream &operator << (std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}

