/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:48:15 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/24 17:02:17 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac > 1)
	{
		PmergeMe<std::vector> algo1;
		std::vector<int> vec;
		std::deque<int> deq;

		if (!parse(av, vec, deq))
			return 1;
		std::cout << PINK << "Std::vector before" << RESET << " : ";
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << " " << vec[i];
		std::cout << std::endl;

		float start1 = std::clock();
		vec = algo1.fordJohnson(vec);
		float end1 = std::clock();

		std::cout << PINK << "Std::vector after" << RESET << " : ";
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << " " << vec[i];
		std::cout << std::endl;

		float time_taken1 = (end1 / 1000) - (start1 / 1000);
		std::cout << PINK "Time to process a range of "<< ORANGE << ac - 1 << " elements" PINK " with std::vector"
		 RESET " : "  << std::setprecision(2) << time_taken1 << "ms" << std::endl;

		/* ************************************************************************ */
		PmergeMe<std::deque> algo2;

		std::cout << PURPLE << "Std::deque before" << RESET << " : ";
		for (size_t i = 0; i < deq.size(); i++)
			std::cout << " " << deq[i];
		std::cout << std::endl;

		float start2 = std::clock();
		deq = algo2.fordJohnson(deq);
		float end2 = std::clock();

		std::cout << PURPLE << "Std::deque after" << RESET << " : ";
		for (size_t i = 0; i < deq.size(); i++)
			std::cout << " " << deq[i];
		std::cout << std::endl;

		float time_taken2 = (end2 / 1000) - (start2 / 1000);
		std::cout << PURPLE "Time to process a range of "<< ORANGE << ac - 1 << " elements" PURPLE " with std::deque"
		RESET " : "  << std::setprecision(2) << time_taken2 << "ms" << std::endl;
	}

	return 0;
}
