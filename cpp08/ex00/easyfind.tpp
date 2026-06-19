/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:43:20 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/22 14:26:45 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


const char* NoOccurrence::what() const throw()
{
	return ("No occurrence has been found");
}

template <typename T>
void	easyfind(T &type, int n)
{
	typename T::iterator it = std::find(type.begin(), type.end(), n);
	if (it != type.end())
		std::cout << "An occurence has been found : " << *it << '\n';
	else
		throw NoOccurrence();
}