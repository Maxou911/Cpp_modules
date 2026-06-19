/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:41:51 by maalwis           #+#    #+#             */
/*   Updated: 2025/09/22 17:38:36 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	current_index = 0;
	std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destroyed" << std::endl;
}

bool	is_number(std::string input)
{
	size_t	i;
	
	i = 0;
	if (input.empty())
	{
		std::cout << "Field cannot be empty : ";
		return (false);
	}
	while (i < input.length()) 
	{
		if (!isdigit(input[i]))
		{
			std::cout << "Please put only positive numbers : ";
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_letter(std::string input)
{
	size_t	i;
	
	i = 0;
	if (input.empty())
	{
		std::cout << "Field cannot be empty : ";
		return (false);
	}
	while (i < input.length()) 
	{
		if (!isalpha(input[i]))
		{
			std::cout << "Please put only letters : ";
			return (false);
		}
		i++;
	}
	return (true);
}

void	PhoneBook::addContact(void)
{
	std::string input;
	
	while (1) 
	{
		std::cout << "First Name : ";
		std::getline(std::cin, input);
		contacts[current_index].setFirstName(input);
		if (is_letter(input))
			break;
	}
	while (1) 
	{
		std::cout << "Last Name : ";
		std::getline(std::cin, input);
		contacts[current_index].setLastName(input);
		if (is_letter(input))
			break;
	}
	while (1) 
	{
		std::cout << "Nickname : ";
		std::getline(std::cin, input);
		contacts[current_index].setNickname(input);
		if (is_letter(input))
			break;
	}
	while (1) 
	{
		std::cout << "Phone Number : ";
		std::getline(std::cin, input);
		contacts[current_index].setPhoneNumber(input);
		if (is_number(input))
			break;
	}
	while (1) 
	{
		std::cout << "Darkest Secret : ";
		std::getline(std::cin, input);
		contacts[current_index].setDarkestSecret(input);
		if (is_letter(input))
			break;
	}

	current_index++;
	if (current_index == 8)
		current_index = 0;
}

void	PhoneBook::displayContacts(int index)
{
	std::cout << contacts[index].getFirstName() << std::endl;
	std::cout << contacts[index].getLastName() << std::endl;
	std::cout << contacts[index].getNickname() << std::endl;
	std::cout << contacts[index].getPhoneNumber() << std::endl;
	std::cout << contacts[index].getDarkestSecret() << std::endl;
}

std::string	longString(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::searchContact(void)
{	
	int	existant_contact = 0;
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;

	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++) 
	{
		if (!contacts[i].getFirstName().empty()) 
		{
			existant_contact = 1;
			std::cout << "|" << std::right << std::setw(10) << i << "|";
			std::cout << std::right << std::setw(10) << longString(contacts[i].getFirstName()) << "|";
			std::cout << std::right << std::setw(10) << longString(contacts[i].getLastName()) << "|";
			std::cout << std::right << std::setw(10) << longString(contacts[i].getNickname()) << "|" << std::endl;
		}
	}
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << "Please put the number of the contact you want to see : ";
	std::string	input;
	while (1) 
	{
		std::getline(std::cin, input);
		
		if (!is_number(input))
			continue ;
		int	index = std::atoi(input.c_str());
		
		if (index < 0 || index > 7)
		{
			std::cout << "Please put a contact within range from 0 to 7 : ";
			continue ;
		}
		if (contacts[index].getFirstName().empty()) 
		{
			if (!existant_contact) 
				break;
			else
			{
				std::cout << "No contact saved at this index. Try again : ";
				continue ;
			}
		}
		displayContacts(index);
		break ;
	}
}
