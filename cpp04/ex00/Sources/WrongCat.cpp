/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:44:31 by maalwis           #+#    #+#             */
/*   Updated: 2025/11/28 15:53:51 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << CYAN "WrongCat is created\n" RESET;
}

WrongCat::~WrongCat()
{
	std::cout << CYAN "WrongCat is destructed\n" RESET;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << ROSE "WrongCat copy WrongCat constructor called\n" RESET;
	this->_type = copy._type;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << ROSE "WrongCat assignment operator called\n" RESET;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << CYAN "WrongCat *meows*\n" RESET;
}