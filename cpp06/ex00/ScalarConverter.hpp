/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:51:50 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/14 14:07:15 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <climits>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		static void convert(const std::string &string);
};