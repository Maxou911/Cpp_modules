/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:53:20 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/14 17:30:30 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

# define PURPLE "\e[0;35m"
# define BOLDPURPLE "\e[1;35m"
# define RED "\e[0;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define ORANGE "\e[1;38;5;202m\002"
# define BLUEISH "\e[1;38;5;111m\002"
# define ROSE "\e[38;5;217m\002"
# define CYAN "\e[0;36m"
# define RESET "\e[0m"

struct Data
{
	int			_age;
	std::string _name;
	std::string _place;
};

class Serializer
{
	public:
		Serializer();
		~Serializer();
		
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};