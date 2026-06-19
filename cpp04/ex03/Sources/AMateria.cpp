/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:21:56 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 16:42:40 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AMateria.hpp"

AMateria::AMateria() : _type("Default") {}

AMateria::AMateria(std::string const &type) : _type(type)
{
	// std::cout << "AMateria " << type << " has been created\n"; 
}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &copy) 
{
	this->_type = copy._type;
	std::cout << "AMateria copy constructor called\n";
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "AMateria assignment operator called\n";
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << target.getName() << " does something\n";
}
