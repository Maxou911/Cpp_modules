/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:31:44 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/16 13:17:21 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>

void	swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}
template <typename T>

T	min(T &a, T &b)
{
	if (a == b)
		return b;
	else if (a < b)
		return a;
	return b;
}

template <typename T>

T	max(T &a, T &b)
{
	if (a == b)
		return b;
	else if (a > b)
		return a;
	return b;
}