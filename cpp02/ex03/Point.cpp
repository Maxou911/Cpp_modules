/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:51:34 by maalwis           #+#    #+#             */
/*   Updated: 2025/10/24 14:20:56 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float a, const float b) : _x(a), _y(b) {}

Point::~Point() {}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY()) {}

Point	&Point::operator=(const Point &copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

float	Point::getX() const
{
	return (this->_x.toFloat());
}

float	Point::getY() const
{
	return (this->_y.toFloat());
}

std::ostream &operator << (std::ostream &out, const Point &f)
{
	out << "(" << f.getX() << "," << f.getY() << ")";
	return (out);
}
