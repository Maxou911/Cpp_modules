/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:21:39 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/25 14:17:21 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(char *input)
{
	_string = std::string(input);
}
RPN::~RPN() {}

RPN::RPN(const RPN &copy)
{
	std::cout << BOLDPURPLE << "COPY CALLED\n" RESET;
	this->_number = copy._number;
	this->_res = copy._res;
	this->_stack = copy._stack;
	this->_string = copy._string;
}

RPN &RPN::operator=(const RPN &other)
{
	std::cout << BOLDPURPLE << "OPERATOR CALLED\n" RESET;
	if (this != &other)
	{
		this->_number = other._number;
		this->_res = other._res;
		this->_stack = other._stack;
		this->_string = other._string;
	}
	return (*this);
}

bool RPN::is_operator(std::string &string)
{
	if (string == "*" || string == "/" || string == "-" || string == "+")
		return true;
	return false;
}

bool RPN::is_number(std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	if (convert_s_to_int(input) >= 10)
		return false;
	return true;
}

int RPN::convert_s_to_int(std::string &str)
{
	int res;
	res = atoi(str.c_str());
	return (res);
}

int	do_op(std::string string, int num1, int num2)
{
	int res = 0;
	if (string == "*")
	{
		if (num2 != 0 && num1 > INT_MAX / num2)
			throw std::runtime_error(RED "Error:" RESET " Overflow !");
		res = num1 * num2;
	}
	else if (string == "+")
		res = num1 + num2;
	else if (string == "-")
		res = num1 - num2;
	else if (string == "/")
	{
		if (num2 == 0)
			throw std::runtime_error(RED "Error:" RESET " Division by zero is impossible !");
		res = num1 / num2;
	}
	return (res);
}

int	RPN::algo_rpn(std::string &token)
{
	if (is_operator(token))
	{
		if (_stack.size() < 2)
			throw std::runtime_error(RED "Error:" RESET " Incorrect rpn use !");
		int a = _stack.top();
		_stack.pop();
		int b = _stack.top();
		_stack.pop();
		_number = do_op(token, b, a);
		_stack.push(_number);
	}
	else if (is_number(token))
	{
		_number = convert_s_to_int(token);
		_stack.push(_number);
	}
	return (_number);
}
void RPN::parse(void)
{
	std::istringstream iss(_string);
	std::string token;

	while (iss >> token)
	{
		if (!is_number(token) && !is_operator(token))
			throw std::runtime_error(RED "Error:" RESET " Invalid token !");
		_res = algo_rpn(token);
	}
	if (_stack.size() != 1)
		throw std::runtime_error(RED "Error:" RESET " Invalid expression !");
	std::cout << _res << std::endl;

}
