/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:53:41 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/16 12:25:16 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int x = rand() % 3;
	Base *base;

	std::cout << "Generated number: " << x << std::endl;
	if (x == 0)
		base = new A();
	else if (x == 1)
		base = new B();
	else
		base = new C();
	return (base);
}
void	identify(Base *p)
{
	if (dynamic_cast<A *>(p)) {
		std::cout << "A\n";
		return ;
	}
	else if (dynamic_cast<B *>(p)) {
		std::cout << "B\n";
		return ;
	}
	else if (dynamic_cast<C *>(p)) {
		std::cout << "C\n";
		return ;
	}
	else {
		std::cout << "Unknown type\n";
		return ;
	}
}
void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A\n";
		return ;
	}
	catch(const std::exception &e) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B\n";
		return ;
	}
	catch(const std::exception &e) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C\n";
		return ;
	}
	catch(const std::exception &e) {}
}

int	main()
{
	srand(time(NULL));
	Base *base = generate();

	identify(base);
	identify(*base);
	delete base;
}
