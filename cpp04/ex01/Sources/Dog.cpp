/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:40:14 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 17:21:27 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << RED "Dog is created\n" RESET;
	this->brain = new Brain;
}

Dog::~Dog()
{
	std::cout << RED "Dog is destructed\n" RESET;
	if (brain)
		delete brain;
}

Dog::Dog(const Dog &copy) : Animal("Dog")
{
	std::cout << ROSE "Dog copy constructor called\n" RESET;
	this->brain = new Brain(*copy.brain);
	this->_type = copy._type;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << ROSE "Dog assignment operator called\n" RESET;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*this->brain = *rhs.brain;
	}
	return (*this);
}

void	Dog::setIdeas(int i, const std::string ideas)
{
	if (i >= 0 && i < 100)
		this->brain->setIdeas(i, ideas);
}

const std::string Dog::getIdeas(int index) const
{
	if (index >= 0 && index < 100)
		return (brain->getIdeas(index));
	return ("");
}

void	Dog::makeSound() const
{
	std::cout << RED << "Dog BARKS !!!\n" RESET;
}
