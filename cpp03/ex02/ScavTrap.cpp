/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:20:42 by maalwis           #+#    #+#             */
/*   Updated: 2025/11/27 13:40:37 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap default constructor called\n";
}
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << ROSE "ScavTrap copy constructor called\n" RESET;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << PURPLE "ScavTrap " << _name << " constructed" RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << PURPLE "ScavTrap " << _name << " destructed" RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << ROSE "ScavTrap assignment operator called\n" RESET;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (_hp <= 0)
	{
		std::cout << "ScavTrap " << colorName(_name) << RED " is dead !\n" RESET;
		return;
	}
	if (_ep <= 0)
	{
		std::cout << "ScavTrap " << colorName(_name) << " has no energy points left !\n";
		return;
	}
	if (_hp > 0 && _ep > 0)
	{
		_ep -= 1;
		std::cout << "ScavTrap " << colorName(_name) << " attacks " << GREEN + target + RESET << " causing " << _ad <<  " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << CYAN "ScavTrap is now in Gate Keeper mode\n" RESET;
}