/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:00:34 by maalwis           #+#    #+#             */
/*   Updated: 2025/10/03 16:42:06 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(const std::string &first_name)
{
	this->first_name = first_name;	
}
void	Contact::setLastName(const std::string &last_name)
{
	this->last_name = last_name;
}
void	Contact::setNickname(const std::string &nickname)
{
	this->nickname = nickname;
}
void	Contact::setPhoneNumber(const std::string &phone_number)
{
	this->phone_number = phone_number;
}
void	Contact::setDarkestSecret(const std::string &darkest_secret)
{
	this->darkest_secret = darkest_secret;
}
Contact::Contact(void)
{
	std::cout << "Contacts slots created" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contacts slot destroyed" << std::endl;
}