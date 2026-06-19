/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:46:51 by maalwis           #+#    #+#             */
/*   Updated: 2025/11/21 17:16:54 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Human");
	ScavTrap b("Zombie");
	
	std::cout << std::endl;
	a.status();
	b.status();
	
	/* ********************************************** */
	std::cout << YELLOW "\n--- Test attack ---\n" RESET;
	a.attack("Zombie");
	b.takeDamage(3);
	b.status();

	/* ********************************************** */
	std::cout << YELLOW "\n--- Test repair ---\n" RESET;
	b.beRepaired(5);
	b.status();

	/* ********************************************** */
	std::cout << YELLOW "\n--- Test energy ---\n" RESET;
	for (int i = 0; i < 12; i++) {
		a.attack("Zombie");
	}

	/* ********************************************** */
	std::cout << YELLOW "\n--- Test copy ---\n" RESET;
	ScavTrap c(a);
	c.attack("Dummy");

	ScavTrap d;
	d = b;
	d.attack("Target");

	/* ********************************************** */
	std::cout << YELLOW "\n--- Test death ---\n" RESET;
	b.takeDamage(50);
	b.attack("Void");
	b.beRepaired(10);
	b.status();

	b.takeDamage(61);
	b.status();
	for (int i = 0; i < 48; i++)
		b.beRepaired(1);
	b.status();

	std::cout<<std::endl;
	b.takeDamage(47);
	b.status();
	b.guardGate();
	
	std::cout << std::endl;
	b.takeDamage(1);
	b.status();
	
	std::cout << std::endl;
	b.attack("Infected");
	
	std::cout << std::endl;
	return (0);
}
