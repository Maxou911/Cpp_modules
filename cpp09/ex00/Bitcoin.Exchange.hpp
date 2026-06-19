/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitcoin.Exchange.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:22:40 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/24 15:38:51 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <utility>

# define PURPLE "\e[0;35m"
# define BOLDPURPLE "\e[1;35m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define ORANGE "\e[1;38;5;202m\002"
# define BLUEISH "\e[1;38;5;111m\002"
# define ROSE "\e[38;5;217m\002"
# define CYAN "\e[0;36m"
# define RESET "\e[0m"

typedef std::map<std::string, float> map;
# define ERROR RED "Error" RESET

class Btc
{
	private:
		float _rate;
		std::string _date;
		std::string _value;
		map _map;
	public:
		Btc();
		~Btc();
		Btc(const Btc &copy);
		Btc &operator=(const Btc &other);

		bool			is_float_valid(std::string &value);
		std::string 	get_value(std::string line);
		bool			check_date(std::string &date);
		bool			check_input_file(std::string &line);
		bool			check_data_file(const std::string &line);
		float			return_input();
		map::iterator	find_date(std::string &date);
		void			parse_input_file(char **av);
		void			parse_data_file(void);
};
