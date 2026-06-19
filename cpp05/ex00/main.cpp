/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:43:50 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/09 17:16:17 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
/********************************************************************** */
	std::cout << YELLOW << "TEST 1\n" RESET;
	
	try
	{
		Bureaucrat Bob("Bob", 5);
		Bob.getGrade();
		std::cout << Bob << std::endl;
		Bob.decrementGrade();
		std::cout << Bob << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

/********************************************************************** */
	std::cout << YELLOW << "TEST 2\n" RESET;
	
	try
	{
		Bureaucrat Mike("Mike", 150);
		Mike.getGrade();
		std::cout << Mike << std::endl;
		Mike.decrementGrade();
		std::cout << Mike << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

/********************************************************************** */
	std::cout << YELLOW << "TEST 3\n" RESET;
	
	try
	{
		Bureaucrat random;
		random.getGrade();
		std::cout << random << std::endl;
		random.decrementGrade();
		std::cout << random << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	
/********************************************************************** */
	std::cout << YELLOW << "TEST 4 ==> COPY\n" RESET;
	
	try
	{
		Bureaucrat Jean("Jean", 50);
		Bureaucrat JeanCopy(Jean);
		JeanCopy.getGrade();
		std::cout << JeanCopy << std::endl;
		JeanCopy.incrementGrade();
		std::cout << JeanCopy << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

/********************************************************************** */
	std::cout << YELLOW << "TEST 5\n" RESET;
	
	try
	{
		Bureaucrat Alice("Alice", 3);
		Alice.getGrade();
		std::cout << Alice << std::endl;
		for (int i = 0; i < 2; i++)
			Alice.incrementGrade();
		std::cout << Alice << std::endl;
		Alice.incrementGrade();
		std::cout << Alice << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}