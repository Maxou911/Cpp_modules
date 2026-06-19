/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:42:46 by maalwis           #+#    #+#             */
/*   Updated: 2026/02/18 13:45:45 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::cout << ORANGE "---------- TEST NORMAL ----------\n" RESET;
		try
		{
			RPN rpn(av[1]);
			rpn.parse();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << ORANGE "\n---------- TEST COPY CONSTRUCTOR ----------\n" RESET;
		try
		{
			RPN original(av[1]);
			RPN copy(original);
			
			copy.parse();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << ORANGE "\n---------- TEST COPY OPERATOR ----------\n" RESET;
		try
		{
			RPN original(av[1]);
			RPN copy(av[1]);

			copy = original;
			copy.parse();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	else
		std::cerr << "Error: Put only 2 arguments please\n";
}
