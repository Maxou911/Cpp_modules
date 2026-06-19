/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:15:30 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/21 14:37:13 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int> a(10);

	a[0] = 10;
	a[1] = 20;
	a[2] = 30;
	try
	{
		a[10] = 100;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << a.size() << std::endl;
	std::cout << a[0] << std::endl;
	std::cout << a[1] << std::endl;
	std::cout << a[2] << std::endl;
	try
	{
		std::cout << a[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception :" << e.what() << std::endl;
	}
	std::cout << "Size a = " << a.size() << std::endl;
	
	Array<unsigned int> b;
	std::cout << "Size b = " << b.size() << std::endl;

	Array<unsigned int> c = 100;
	std::cout << "Size c = " << c.size() << std::endl;

	Array<unsigned int> d = c;
	std::cout << "Size d = " << d.size() << std::endl;

	Array<unsigned int> e(50);
	e = c;
	std::cout << "Size e = " << e.size() << std::endl;
	return (0);
}

/* #include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		// std::cout << "number[i] = " << numbers[i] << std::endl;
		// std::cout << "mirror[i] = " << mirror[i] << std::endl;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
} */
