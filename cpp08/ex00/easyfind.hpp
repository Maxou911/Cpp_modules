/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:43:19 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/22 14:42:06 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <deque>
#include <list>

# define ORANGE "\e[1;38;5;202m\002"
# define RESET "\e[0m"

template <typename T>

void	easyfind(T &type, int n);

class NoOccurrence : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#include "easyfind.tpp"