/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:43:50 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/13 15:53:31 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Bureaucrat.hpp"
#include "../Includes/AForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/Intern.hpp"

int	main(void)
{
	std::cout << YELLOW << "TEST 1\n" RESET;
	Bureaucrat	boss1("Boss1", 25);
	Bureaucrat	intern1("Intern1", 5);
	AForm *form1 = new PresidentialPardonForm("Pres");

	intern1.signForm(*form1);
	boss1.signForm(*form1);
	intern1.executeForm(*form1);
	boss1.executeForm(*form1);
	delete form1;
	
/* ********************************************************************************** */
	std::cout << YELLOW << "TEST 2\n" RESET;
	Bureaucrat	boss2("Boss2", 45);
	Bureaucrat	intern2("Intern2", 46);
	AForm *form2 = new RobotomyRequestForm("Robo");

	intern2.signForm(*form2);
	boss2.signForm(*form2);
	intern2.executeForm(*form2);
	boss2.executeForm(*form2);
	delete form2;

/* ********************************************************************************** */
	std::cout << YELLOW << "TEST 3\n" RESET;
	Bureaucrat	boss3("Boss3", 146);
	Bureaucrat	intern3("Intern3", 137);
	AForm *form3 = new ShrubberyCreationForm("Shrute");

	intern3.signForm(*form3);
	boss3.signForm(*form3);
	intern3.executeForm(*form3);
	boss3.executeForm(*form3);
	delete form3;
	/* *********************************************************************************** */
	std::cout << YELLOW << "TEST INTERN\n" RESET;
	try
	{
		Bureaucrat	boss4("Boss4", 146);
		Bureaucrat	intern4("Intern4", 137);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("ShrubberyCreation", "Bender");
		intern4.signForm(*rrf);
		boss4.signForm(*rrf);
		intern4.executeForm(*rrf);
		boss4.executeForm(*rrf);
		delete rrf;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what();
	}
	return (0);
}
