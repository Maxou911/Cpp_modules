/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:43:50 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/12 18:31:29 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << YELLOW << "TEST 1\n" RESET;
	try
	{
		Bureaucrat	boss("Boss", 1);
		Bureaucrat	intern("Intern", 150);
		Form		contract("Contract", 50, 50);

		std::cout << contract << std::endl;
		intern.signForm(contract);
		std::cout << contract << std::endl;

		boss.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
/* ********************************************************************************** */
	
	std::cout << YELLOW << "TEST 2\n" RESET;
	try
	{
		Form contract("Contract", 50, 200);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
/* ********************************************************************************** */
	std::cout << YELLOW << "TEST 3\n" RESET;
	try
	{
		Bureaucrat	boss("Boss", 1);
		Bureaucrat	intern("Intern", 150);
		Form		contract("Contract", 5, 23);

		std::cout << contract << std::endl;
		intern.signForm(contract);
		std::cout << contract << std::endl;

		boss.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
