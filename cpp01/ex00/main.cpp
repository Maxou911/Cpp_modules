/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:00:16 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/04 16:22:42 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string name = av[1];
		Zombie *zombie = newZombie(name);
		zombie->announce();
		delete (zombie);
		randomChump(name);
	}
}