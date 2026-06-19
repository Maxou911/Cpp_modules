/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point_operateur.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:33:18 by maalwis           #+#    #+#             */
/*   Updated: 2025/10/02 16:37:24 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	Point::operator==(const Point &other) const
{
	return (this->_x == other._x && this->_y == other._y);
}