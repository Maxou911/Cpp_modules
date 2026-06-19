/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:49:35 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/17 16:08:00 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <limits>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <climits>

# define PURPLE "\e[0;35m"
# define BOLDPURPLE "\e[1;35m"
# define RED "\e[0;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define ORANGE "\e[1;38;5;202m\002"
# define BLUEISH "\e[1;38;5;111m\002"
# define ROSE "\e[38;5;217m\002"
# define CYAN "\e[0;36m"
# define RESET "\e[0m"

class Span
{
	private:
		std::list<int> _list;
		unsigned int	 _n;
	public:
	
		Span(unsigned int n);
		Span(const Span &copy);
		Span &operator=(const Span &other);
		~Span();
		
		class NoMoreNumber : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughNumbers : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		void addNumber(int x);
		template <typename It>
		void addMultipleNumbers(It it, It it_end)
		{
			if (_list.size() + std::distance(it, it_end) > this->_n)
				throw NoMoreNumber();
			_list.insert(_list.end() ,it, it_end);
		}
		unsigned int shortestSpan();
		unsigned int longestSpan();

		std::list<int>::iterator begin();
		std::list<int>::iterator end();
};