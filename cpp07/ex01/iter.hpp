/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:15:23 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/16 15:43:52 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename F>

void iter(T *a, const int size, F &f)
{
	int i = 0;
	while (i < size) {
		f(a[i]);
		i++;
	}
}
template <typename T, typename F>
void iter(const T *a, const int size, const F &f)
{
	int i = 0;
	while (i < size) {
		f(a[i]);
		i++;
	}
}
