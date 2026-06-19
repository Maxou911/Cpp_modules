/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:59:47 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/10 12:05:43 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << PURPLE "DiamondTrap_clap_name default constructor called\n" RESET;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << BOLDPURPLE "DiamondTrap " << _name << " constructed\n" RESET;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BOLDPURPLE "DiamondTrap " << _name << " destructed" RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy)
{
	_name = copy._name;
	_hp = copy._hp;
	_ep = copy._ep;
	_ad = copy._ad;
	std::cout << ROSE "DiamondTrap copy constructor called\n" RESET;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	std::cout << ROSE "DiamondTrap assignment operator called\n" RESET;
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << BLUEISH "Hello I'm " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl << RESET;
}