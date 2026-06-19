/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:21:34 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/25 14:18:25 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <climits>

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

//Stack ==> LIFO, Last In First Out
class RPN
{
	private:
		int	_number;
		int	_res;
		std::stack<int> _stack;
		std::string _string;
	public:
		RPN(char *input);
		RPN();
		~RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &other);

		bool	is_operator(std::string &string);
		bool	is_number(std::string &input);
		int		algo_rpn(std::string &token);
		void	parse(void);
		int		convert_s_to_int(std::string &str);
};
