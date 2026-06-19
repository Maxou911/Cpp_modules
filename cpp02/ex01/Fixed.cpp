/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:18:58 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/04 14:14:44 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called\n";
	this->_value = n << _fractionalBits;
}

Fixed::Fixed(float f)
{
	std::cout << "Float constructor called\n";
	this->_value = roundf(f * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignement operator called\n";
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
	std::cout << "getRawBits member function called\n";
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
