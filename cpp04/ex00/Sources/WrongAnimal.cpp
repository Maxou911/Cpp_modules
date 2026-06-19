/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:43:51 by maalwis           #+#    #+#             */
/*   Updated: 2025/11/28 15:53:59 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
	std::cout << PURPLE "WrongAnimal is created\n" RESET;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << PURPLE "WrongAnimal is destructed\n" RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << ROSE "Copy constructor called\n" RESET;
	this->_type = copy._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << ROSE "WrongAnimal assignment operator called\n" RESET;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << ORANGE "WrongAnimal makes a sound !\n" RESET;
}

const std::string	WrongAnimal::getType() const {return _type;}