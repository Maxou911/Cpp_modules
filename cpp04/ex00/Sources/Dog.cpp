/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:40:14 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 13:56:42 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << RED "Dog is created\n" RESET;
}

Dog::~Dog()
{
	std::cout << RED "Dog is destructed\n" RESET;
}

Dog::Dog(const Dog &copy)
{
	std::cout << ROSE "Dog copy constructor called\n" RESET;
	this->_type = copy._type;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << ROSE "Dog assignment operator called\n" RESET;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << RED << "Dog BARKS !!!\n" RESET;
}