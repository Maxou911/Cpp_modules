/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:47:09 by maalwis           #+#    #+#             */
/*   Updated: 2025/11/27 13:41:17 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hp(10), _ep(10), _ad(0) {}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << PURPLE "ClapTrap " << _name << " constructed" RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << PURPLE "ClapTrap " << _name << " destructed" RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << ROSE "Copy constructor called\n" RESET;
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_ad = copy._ad;
	this->_ep = copy._ep;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ad = other._ad;
		this->_ep = other._ep;
	}
	std::cout << ROSE "Assignment operator called\n" RESET;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (_hp <= 0)
	{
		std::cout << colorName(_name) << RED " is dead !\n" RESET;
		return;
	}
	if (_ep <= 0)
	{
		std::cout << colorName(_name) << " has no energy points left !\n";
		return;
	}
	if (_hp > 0 && _ep > 0)
	{
		_ep -= 1;
		std::cout << colorName(_name) << " attacks " << GREEN + target + RESET << " causing " << _ad <<  " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout << colorName(_name) << RED " is already dead !\n" RESET;
		return;
	}

	if (amount >= _hp)
		_hp = 0;
	else
		_hp -= amount;

	std::cout << colorName(_name) << " takes " << amount << " points of damage!" << std::endl;

	if (_hp == 0)
		std::cout << colorName(_name) << RED " died !\n" RESET;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout << colorName(_name) << RED " is dead !\n" RESET;
		return;
	}
	if (_ep <= 0)
	{
		std::cout << colorName(_name) << " has no energy points left !\n";
		return;
	}
	else if (_ep > 0)
	{
		_ep -= 1;
		_hp += amount;
		std::cout << colorName(_name) << " heals itself " << amount << " hp" << std::endl;
	}
}

void ClapTrap::status(void) const
{
	std::cout << "STATUS OF " << colorName(_name) << " : HP = " << _hp \
	<< ", EP = " << _ep << ", AD = " << _ad << std::endl;
}

std::string ClapTrap::colorName(const std::string &name) const
{
	if (name == "Zombie")
		return (GREEN + _name + RESET);
	if (name == "Human")
		return (BLUE + _name + RESET);
	return (name);
}
