/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:44:30 by maalwis           #+#    #+#             */
/*   Updated: 2025/09/23 17:42:24 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();

		void	setName(const std::string &n);
		void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif