/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:46:51 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/10 11:57:52 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap a("Baby");
	std::cout << std::endl;

	a.status();

	/* ********************************************* */
	std::cout << YELLOW "\n--- Test attack ---\n" RESET;
	a.attack("DROIDE");
	
	/* ********************************************* */
	std::cout << YELLOW "\n--- Test repair ---\n" RESET;
	a.beRepaired(50);
	a.status();
	
	/* ********************************************* */
	a.whoAmI();
	
	/* ********************************************* */
	std::cout << YELLOW "\n--- Test take damage ---\n" RESET;
	a.takeDamage(10);
	a.status();
	
	/* ********************************************* */
	std::cout << YELLOW "\n--- Test copy ---\n" RESET;
	DiamondTrap b(a);
	b.status();
	std::cout << std::endl;
	
	DiamondTrap c;
	c = b;
	c.status();

	std::cout << std::endl;
}