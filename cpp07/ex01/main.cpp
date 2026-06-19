/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:15:30 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/16 15:48:01 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void ft_toupper(char &a)
{
	if (a >= 97 && a <= 122)
		a -= 32;
}

void	ft_print(const char &a)
{
	std::cout << a;
}

int	ft_mul(int &x)
{
	return (x = x * x);
}

void	ft_print_int(int &a)
{
	std::cout << a << std::endl;
}

int	main(void)
{
	char	a[] = "abcde";
	int		size = 3;
	
	::iter(a, size, ft_toupper);
	std::cout << a << std::endl;

	const char	b[] = "abcde";
	int		size_b = 3;
	
	::iter(b, size_b, ft_print);
	std::cout << std::endl;

	int	x[] = {1, 5, 3};
	::iter(x, size, ft_mul);
	::iter(x, size, ft_print_int);
}