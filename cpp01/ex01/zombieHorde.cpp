/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:44:15 by maalwis           #+#    #+#             */
/*   Updated: 2025/11/28 16:44:31 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie = new Zombie[N];
	if (!zombie) {
		std::cout << "Memory allocation failed\n";
		return (NULL);
	}
	for (int i = 0; i < N; i++) {
		zombie[i].setName(name);
	}
	return (zombie);
}