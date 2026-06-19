/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:40:24 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 17:20:43 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << CYAN "Cat is created\n" RESET;
	this->brain = new Brain;
}

Cat::~Cat()
{
	std::cout << CYAN "Cat is destructed\n" RESET;
	if (brain)
		delete brain;
}

Cat::Cat(const Cat &copy) : Animal("Cat")
{
	std::cout << ROSE "Cat copy Cat constructor called\n" RESET;
	this->brain = new Brain(*copy.brain);
	this->_type = copy._type;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << ROSE "Cat assignment operator called\n" RESET;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*this->brain = *rhs.brain;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << CYAN "Cat *meows*\n" RESET;
}

void	Cat::setIdeas(int i, const std::string ideas)
{
	if (i >= 0 && i < 100)
		this->brain->setIdeas(i, ideas);
}

const std::string Cat::getIdeas(int index) const
{
	if (index >= 0 && index < 100)
		return (brain->getIdeas(index));
	return ("");
}