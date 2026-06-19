/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:46:51 by maalwis           #+#    #+#             */
/*   Updated: 2025/11/21 17:08:39 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* int	main(void)
{
	ClapTrap a("Human");
	ClapTrap b("Zombie");
	b = a;
	b.attack("Dog");
	b.takeDamage(5);
	b.beRepaired(1);
} */

int main()
{
	ClapTrap a("Human");
	ClapTrap b("Zombie");

	/* ********************************************** */
	std::cout << YELLOW "\n--- Test attack ---\n" RESET;
	a.attack("Zombie");
	b.takeDamage(3);
	a.status();
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
	a.status();
	
	/* ********************************************** */
	std::cout << YELLOW "\n--- Test copy ---\n" RESET;
	ClapTrap c(a);
	c.attack("Test");

	ClapTrap d;
	d = b;
	d.attack("Target");
	
	/* ********************************************** */
	std::cout << YELLOW "\n--- Test death ---\n" RESET;
	b.takeDamage(50);
	b.attack("Void");
	b.beRepaired(10);
	b.status();

	std::cout << std::endl;
	return (0);
}
