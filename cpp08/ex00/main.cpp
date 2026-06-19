/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:43:16 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/22 14:48:02 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::cout << ORANGE "TEST 1: CONTAINER DEQUE\n" RESET;
	try
	{
		std::deque<int> tab1;

		tab1.push_front(10); // ajoute des elements en debut de liste
		tab1.push_front(15);
		tab1.push_front(20);
		easyfind(tab1, 15); // trouve la premiere occurence du deuxieme parametre int n
		tab1.pop_front(); // enleve des elements en debut de list
		tab1.pop_front();
		easyfind(tab1, 15);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << ORANGE "TEST 2: CONTAINER VECTOR\n" RESET;
	try
	{
		std::vector<int> tab2;

		tab2.push_back(10); // ajoute des elements en fin de liste
		tab2.push_back(15);
		tab2.push_back(20);
		tab2.push_back(100);
		easyfind(tab2, 10);
		easyfind(tab2, 30);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << ORANGE "TEST 3: CONTAINER LIST\n" RESET;
	try
	{
		std::list<int> tab3;

		tab3.push_back(10);
		tab3.push_back(20);
		easyfind(tab3, 10);
		easyfind(tab3, 20);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}