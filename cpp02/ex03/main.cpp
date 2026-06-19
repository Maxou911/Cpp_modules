/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:18:38 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/09 13:20:48 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point p;
	
	std::cout << YELLOW "Points du triangle :" RESET "\nA = 0,0 \nB = 5,0\nC = 0,5\n\n";

	std::cout << YELLOW "TEST :\n" RESET;
////////////////////////////////////////////////////////////////////////
	Point p1(1, 1);
	if (bsp(a, b, c, p1))
		std::cout << "P1" << p1 << " dans le triangle" << std::endl;
	else if (is_on_edge(a, b, c, p1))
		std::cout << "P1" << p1 << " sur une arrete" << std::endl;
	else
		std::cout << "P1" << p1 << " en dehors du triangle\n";
/////////////////////////////////////////////////////////////////////////
	Point p2(8, 6);
	if (bsp(a, b, c, p2))
		std::cout << "P2" << p2 << " dans le triangle" << std::endl;
	else if (is_on_edge(a, b, c, p2))
		std::cout << "P1" << p2 << " sur une arrete" << std::endl;
	else
		std::cout << "P2" << p2 << " en dehors du triangle\n";
////////////////////////////////////////////////////////////////////////
	Point p3(2.5, 0);
	if (bsp(a, b, c, p3))
		std::cout << "P3" << p3 << " dans le triangle" << std::endl;
	else if (is_on_edge(a, b, c, p3))
		std::cout << "P3" << p3 << " sur une arrete" << std::endl;
	else
		std::cout << "P3" << p3 << " sur le triangle\n";
////////////////////////////////////////////////////////////////////////
	Point p4(0.31, 4.4);
	if (bsp(a, b, c, p4))
		std::cout << "P4" << p4 << " dans le triangle" << std::endl;
	else if (is_on_edge(a, b, c, p4))
		std::cout << "P4" << p4 << " sur une arrete" << std::endl;
	else
		std::cout << "P4" << p4 << " en dehors du triangle\n";
////////////////////////////////////////////////////////////////////////
	Point p5(4.5, 0.2);
	if (bsp(a, b, c, p5))
		std::cout << "P5" << p5 << " dans le triangle" << std::endl;
	else if (is_on_edge(a, b, c, p5))
		std::cout << "P5" << p5 << " sur une arrete" << std::endl;
	else
		std::cout << "P5" << p5 << " en dehors du triangle\n";
////////////////////////////////////////////////////////////////////////
	return (0);
}
