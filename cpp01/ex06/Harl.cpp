/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:04:00 by maalwis           #+#    #+#             */
/*   Updated: 2025/09/26 18:01:30 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "An angry Harl has come\n\n";
}

Harl::~Harl(void)
{
	std::cout << "An angry Harl is gone\n";
}



void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my"
	 << "7XL-double-cheese-triple-pickle-specialketchup burger.\n";
	std::cout << "I really do!\n\n";
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn’t put enough bacon in my burger!"
	<< "If you did, I wouldn’t be asking for more!\n\n";
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming for years,"
	<< " whereas you started working here just last month.\n\n";
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void	Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int	index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			index = i;
	}

	switch (index) {
		case 0: (this->*functions[0])();
		case 1: (this->*functions[1])();
		case 2: (this->*functions[2])();
		case 3: (this->*functions[3])(); break;
		default: std::cout << "[ Probably complaining about insignificant problems ]\n\n";
	}
}
