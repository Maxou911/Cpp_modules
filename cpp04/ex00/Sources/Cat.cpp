/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:40:24 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 13:56:40 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << CYAN "Cat is created\n" RESET;
}

Cat::~Cat()
{
	std::cout << CYAN "Cat is destructed\n" RESET;
}

Cat::Cat(const Cat &copy)
{
	std::cout << ROSE "Cat copy Cat constructor called\n" RESET;
	this->_type = copy._type;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << ROSE "Cat assignment operator called\n" RESET;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << CYAN "Cat *meows*\n" RESET;
}