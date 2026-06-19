/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:00:39 by maalwis           #+#    #+#             */
/*   Updated: 2025/09/23 17:41:38 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		std::string darkest_secret;

	public:
		void	setFirstName(const std::string &first_name);
		void	setLastName(const std::string &last_name);
		void	setNickname(const std::string &nickname);
		void	setPhoneNumber(const std::string &phone_number);
		void	setDarkestSecret(const std::string &darkest_secret);

		std::string getFirstName(){
			return (first_name);
		}
		std::string getLastName(){
			return (last_name);
		}
		std::string getNickname(){
			return (nickname);
		}
		std::string getPhoneNumber(){
			return (phone_number);
		}
		std::string getDarkestSecret(){
			return (darkest_secret);
		}
		
		Contact(void);
		~Contact(void);
};

#endif