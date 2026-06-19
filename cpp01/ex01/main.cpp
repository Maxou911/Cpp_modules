/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:44:25 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/04 16:05:15 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		std::string name = av[1];
		int	n = atoi(av[2]);
		if (n < 0 || n > 500)
			return (1);
		Zombie *zombie = zombieHorde(n, name);
		for (int i = 0; i < n; i++)
			zombie->announce();

		delete[] zombie;
	}
}