/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:51:58 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/15 11:40:47 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

static bool	handle_err(const std::string &string)
{
	if (string == "nan" || string == "nanf")
	{
		std::cout << "char: Impossible\n"
		<< "int: Impossible\n"
		<< "float: nanf\n"
		<< "double: nan\n";
		return true;
	}
	if (string == "+inf" || string == "+inff")
	{
		std::cout << "char: Impossible\n"
		<< "int: Impossible\n"
		<< "float: +inff\n"
		<< "double: +inf\n";
		return true;
	}
	if (string == "-inf" || string == "-inff")
	{
		std::cout << "char: Impossible\n"
		<< "int: Impossible\n"
		<< "float: -inff\n"
		<< "double: -inf\n";
		return true;
	}
	return false;
}

void ScalarConverter::convert(const std::string &string)
{
	if (handle_err(string))
		return ;

	double value;
	std::stringstream ss(string);
	ss >> value;

	char c = static_cast<char>(value);
	double d = static_cast<double>(value);
	int i = static_cast<int>(value);
	float f = static_cast<float>(value);

	if (ss.fail() || value < 32 || value > 126)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";

	if (ss.fail() || value < INT_MIN || value > INT_MAX)
		std::cout << "int: Non displayable\n";
	else
		std::cout << "int: "<< i << '\n';

	if (ss.fail())
		std::cout << "float: Non displayable\n";
	else if (value == i)
		std::cout << "float: " << f << ".0f\n";
	else
		std::cout << "float: " << f << "f\n";

	if (ss.fail())
		std::cout << "double: Non displayable\n";
	else if (value == i)
		std::cout << "double: " << d << ".0\n";
	else
		std::cout << "double: " << d << "\n";
}
