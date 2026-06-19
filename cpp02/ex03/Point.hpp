/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:51:27 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/04 13:55:08 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

# define YELLOW "\e[1;33m"
# define RESET   "\001\033[0m\002"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
		int			_value;

	public:
		Point();
		Point(const float a, const float b);
		Point(const Point &copy);
		Point &operator=(const Point &copy);
		~Point();

		float getX() const;
		float getY() const;
		
		bool	operator==(const Point &other) const;
};

bool is_on_edge(Point const a, Point const b, Point const c, Point const p);
bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream &operator << (std::ostream &out, const Point &f);

#endif