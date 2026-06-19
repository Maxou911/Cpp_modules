/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator_Incr_Decr.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:38:41 by maalwis           #+#    #+#             */
/*   Updated: 2025/10/02 14:56:51 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator++() // Pre-incr
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) // Post-incr
{
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed &Fixed::operator--() // Pre-incr
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int) // Post-incr
{
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}