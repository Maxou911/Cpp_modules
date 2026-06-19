/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:35:32 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/13 15:49:26 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Intern.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/Bureaucrat.hpp"


Intern::Intern() {}
Intern::~Intern() {}


AForm	*Intern::makeShrub(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobot(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePres(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string levels[] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	
	AForm	*(Intern::*functions[])(const std::string &) = {&Intern::makePres, \
	&Intern::makeRobot,
	&Intern::makeShrub};

	for (int i = 0; i < 3; i++)
	{
		if (name == levels[i])
		{
			std::cout << "Intern creates " << name << " targeted at " << target << '\n';
			return (this->*functions[i])(target);
		}
	}
	throw 
		std::runtime_error ("Intern cannot create form because " + name + " is unknown\n");
	return (NULL);
}