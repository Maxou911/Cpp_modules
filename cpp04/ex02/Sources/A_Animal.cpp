/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:57:23 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 16:43:34 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/A_Animal.hpp"

A_Animal::A_Animal() 
{
	std::cout << PURPLE "Animal is created\n" RESET;
}

A_Animal::~A_Animal()
{
	std::cout << PURPLE "Animal is destructed\n" RESET;
}
A_Animal::A_Animal(const std::string &type) : _type(type) {}

A_Animal::A_Animal(const A_Animal &copy)
{
	std::cout << ROSE "Animal copy constructor called\n" RESET;
	this->_type = copy._type;
}

A_Animal &A_Animal::operator=(const A_Animal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << ROSE "Animal assignment operator called\n" RESET;
	return (*this);
}

void	A_Animal::makeSound() const
{
	std::cout << PURPLE "Animal makes a sound !\n" RESET;
}

const std::string	A_Animal::getType() const {return _type;}