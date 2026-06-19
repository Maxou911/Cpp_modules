/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:49:32 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/17 16:10:27 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void test_normal(void)
{
	std::cout << ORANGE "TEST NORMAL:\n" RESET;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		for (std::list<int>::iterator it = sp.begin(); it != sp.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << GREEN "Longest span: " RESET << sp.longestSpan() << std::endl;
		std::cout << GREEN "Shortest span: " RESET << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << '\n';
	}
}

void	test_overflow(void)
{
	std::cout << ORANGE "TEST OVERFLOW:\n" RESET;
	try
	{
		Span sp(2);
		
		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);
		
		// sp.addNumber(-14);
		// sp.addNumber(-10);

		for (std::list<int>::iterator it = sp.begin(); it != sp.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << GREEN "Longest span: " RESET << sp.longestSpan() << std::endl;
		std::cout << GREEN "Shortest span: " RESET << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	test_exception_too_much_numbers(void)
{
	std::cout << ORANGE "TEST EXCEPTION TOO MUCH NUMBERS: \n" RESET;
	try
	{
		Span sp = Span(4);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		for (std::list<int>::iterator it = sp.begin(); it != sp.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << GREEN "Longest span: " RESET << sp.longestSpan() << std::endl;
		std::cout << GREEN "Shortest span: " RESET << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << '\n';
	}
}

void	test_exception_not_enough_numbers(void)
{
	std::cout << ORANGE "TEST EXCEPTION NOT ENOUGH NUMBERS: \n" RESET;
	try
	{
		Span sp = Span(0);
		sp.addNumber(6);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << '\n';
	}
	try
	{
		Span sp = Span(1);
		sp.addNumber(6);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << '\n';
	}
}
void	test_large_numbers(void)
{
	std::cout << ORANGE "TEST LARGE NUMBERS: \n" RESET;
	try
	{
		int i = 0;
		Span sp = Span(100000);
		while (i < 100000)
			sp.addNumber(i++);
		std::cout << GREEN "Longest span: " RESET << sp.longestSpan() << std::endl;
		std::cout << GREEN "Shortest span: " RESET << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << '\n';
	}
}

void	test_same_numbers(void)
{
	std::cout << ORANGE "TEST SAME NUMBER: \n" RESET;
	Span sp(5);
	
	sp.addNumber(1);
	sp.addNumber(1);
	std::cout << GREEN "Longest span: " RESET << sp.longestSpan() << std::endl;
	std::cout << GREEN "Shortest span: " RESET << sp.shortestSpan() << std::endl;
}

void	test_multiple_numbers()
{
	std::cout << ORANGE "TEST ADD MULTIPLE NUMBERS: \n" RESET;

	Span sp(5);
	std::list<int> src(3,9);

	sp.addMultipleNumbers(src.begin(), src.end());
	for (std::list<int>::iterator it = sp.begin(); it != sp.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	/* *********************************************************************** */

	Span test2(4);
	int arr[] = {4, 8, 15, 16, 12};

	test2.addMultipleNumbers(arr, arr + 4);
	for (std::list<int>::iterator it = test2.begin(); it != test2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	/* *********************************************************************** */
	try {
		Span sp3(5);
		std::list<int> src3;
		src3.push_back(10);
		src3.push_back(3);
		src3.push_back(20);
		
		sp3.addMultipleNumbers(src3.begin(), src3.end());
		for (std::list<int>::iterator it = sp3.begin(); it != sp3.end(); ++it)
				std::cout << *it << " ";
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Span sp3(2);
		std::list<int> src3;
		src3.push_back(10);
		src3.push_back(3);
		src3.push_back(20);
	
		sp3.addMultipleNumbers(src3.begin(), src3.end());
		for (std::list<int>::iterator it = sp3.begin(); it != sp3.end(); ++it)
			std::cout << *it << " ";
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	test_other_containers()
{
	std::cout << ORANGE "TEST OTHER CONTAINERS: \n" RESET;
	Span sp(5);
	std::vector<int> src;
	src.push_back(10);
	src.push_back(3);
	src.push_back(20);

	sp.addMultipleNumbers(src.begin(), src.end());

	for (std::list<int>::iterator it = sp.begin(); it != sp.end(); ++it)
		std::cout << *it << std::endl;
}

void test_copy(void)
{
	std::cout << ORANGE "TEST COPY:\n" RESET;
	try
	{
		Span sp(5);

		Span copy(sp);
		copy.addNumber(6);
		copy.addNumber(3);
		copy.addNumber(17);
		copy.addNumber(9);
		copy.addNumber(11);
		for (std::list<int>::iterator it = copy.begin(); it != copy.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << GREEN "Longest span: " RESET << copy.longestSpan() << std::endl;
		std::cout << GREEN "Shortest span: " RESET << copy.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << '\n';
	}
}

void test_operator_copy(void)
{
	std::cout << ORANGE "TEST COPY OPERATOR:\n" RESET;
	try
	{
		Span sp(5);

		Span copy = sp;
		copy.addNumber(6);
		copy.addNumber(3);
		copy.addNumber(17);
		copy.addNumber(9);
		copy.addNumber(11);
		for (std::list<int>::iterator it = copy.begin(); it != copy.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << GREEN "Longest span: " RESET << copy.longestSpan() << std::endl;
		std::cout << GREEN "Shortest span: " RESET << copy.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << '\n';
	}
}

int main(void)
{
	test_normal();
	test_overflow();
	test_exception_too_much_numbers();
	test_exception_not_enough_numbers();
	test_large_numbers();
	test_same_numbers();
	test_multiple_numbers();
	test_other_containers();
	test_copy();
	test_operator_copy();
	return (0);
}
