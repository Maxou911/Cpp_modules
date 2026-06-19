/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:15:59 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 16:55:53 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain has been created\n";
}

Brain::~Brain()
{
	std::cout << "Brain has been deleted\n";
}

Brain::Brain(const Brain &copy)
{
	std::cout << ROSE "Brain copy constructor called\n" RESET;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << ROSE "Brain copy assignement operator called\n" RESET;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

void	Brain::setIdeas(int i, const std::string ideas)
{
	if (i >= 0 && i < 100)
		this->_ideas[i] = ideas;
}

const std::string Brain::getIdeas(int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (_ideas[index]);
}