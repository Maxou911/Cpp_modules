/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:18:57 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/10 12:05:56 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
	_hp = 100;
	_ad = 30;
	std::cout << PURPLE "FragTrap default constructor called\n" RESET;
}
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << ROSE "FragTrap copy constructor called\n" RESET;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hp = 100;
	_ad = 30;
	std::cout << PURPLE "FragTrap " << _name << " constructed" RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << PURPLE "FragTrap " << _name << " destructed" RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << ROSE "FragTrap assignment operator called\n" RESET;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (_hp <= 0)
	{
		std::cout << "FragTrap " << colorName(_name) << RED " is dead !\n" RESET;
		return;
	}
	if (_ep <= 0)
	{
		std::cout << "FragTrap " << colorName(_name) << " has no energy points left !\n";
		return;
	}
	if (_hp > 0 && _ep > 0)
	{
		_ep -= 1;
		std::cout << "FragTrap " << colorName(_name) << " attacks " << GREEN + target + RESET << " causing " << _ad <<  " points of damage!" << std::endl;
	}
}

void FragTrap::highFiveGuys(void)
{
	std::cout << CYAN "FragTrap high fives\n" RESET;
}