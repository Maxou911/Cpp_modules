/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:57:23 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 16:31:55 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Animal.hpp"

Animal::Animal() 
{
	std::cout << PURPLE "Animal is created\n" RESET;
}

Animal::Animal(const std::string &type) : _type(type) {}

Animal::~Animal()
{
	std::cout << PURPLE "Animal is destructed\n" RESET;
}

Animal::Animal(const Animal &copy)
{
	std::cout << ROSE "Animal copy constructor called\n" RESET;
	this->_type = copy._type;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << ROSE "Animal assignment operator called\n" RESET;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << PURPLE "Animal makes a sound !\n" RESET;
}

const std::string	Animal::getType() const {return _type;}