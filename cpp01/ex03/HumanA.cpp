/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:28:02 by maalwis           #+#    #+#             */
/*   Updated: 2025/09/24 14:37:34 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << name << " is created" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << name << " is destroyed" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with " << weapon.getType() << std::endl;
}