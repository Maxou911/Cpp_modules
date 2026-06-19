/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:29:15 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/04 13:24:08 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &t) : type(t)
{
	std::cout << type << " is created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << type << " is destroyed" << std::endl;
}

void	Weapon::setType(const std::string &newType)
{
	type = newType;
}

std::string Weapon::getType()
{
	return (type);
}
