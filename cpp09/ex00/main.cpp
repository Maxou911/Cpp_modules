/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:22:56 by maalwis           #+#    #+#             */
/*   Updated: 2026/02/18 13:53:22 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitcoin.Exchange.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::cout << ORANGE "---------- TEST NORMAL ----------\n\n" RESET;
		Btc btc;
		btc.parse_data_file();
		btc.parse_input_file(av);
		std::cout << '\n';

		std::cout << ORANGE "---------- TEST COPY CONSTRUCTOR----------\n\n" RESET;
		Btc copy(btc);
		copy.parse_data_file();
		copy.parse_input_file(av);
		std::cout << '\n';

		std::cout << ORANGE "---------- TEST COPY OPERATOR ----------\n\n" RESET;
		Btc operator_copy;
		
		operator_copy = copy;
		operator_copy.parse_data_file();
		operator_copy.parse_input_file(av);
	}
	else
	{
		std::cout << RED "Please put 2 parameters, (./btc + file)\n" RESET;
		return (1);
	}
	return (0);
}
