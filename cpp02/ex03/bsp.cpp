/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:51:14 by maalwis           #+#    #+#             */
/*   Updated: 2025/10/24 18:55:05 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float sign(Point const a, Point const b, Point const c)
{
	return (((a.getX() - c.getX()) * (b.getY() - c.getY())) - \
	((b.getX() - c.getX()) * (a.getY() - c.getY())));
}

bool is_on_edge(Point const a, Point const b, Point const c, Point const p)
{
	float d1, d2, d3;
	bool is_equal;
	
	d1 = sign(p, a, b);
	d2 = sign(p, b, c);
	d3 = sign(p, c, a);

	is_equal = (d1 == 0) || (d2 == 0) || (d3 == 0);
	
	return (is_equal);
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	float d1, d2, d3;
	bool is_neg, is_pos;
	
	d1 = sign(p, a, b);
	d2 = sign(p, b, c);
	d3 = sign(p, c, a);

	is_neg = (d1 < 0) && (d2 < 0) && (d3 < 0);
	is_pos = (d1 > 0) && (d2 > 0) && (d3 > 0);

	return (is_neg || is_pos);
}

