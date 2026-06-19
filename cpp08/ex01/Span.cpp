/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:49:38 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/17 15:26:43 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) 
{
	if (n <= 1)
		throw NotEnoughNumbers();
}

Span::~Span() {}

Span::Span(const Span &copy)
{
	this->_list = copy._list;
	this->_n = copy._n;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_list = other._list;
		this->_n = other._n;
	}
	return (*this);
}

void Span::addNumber(int x)
{
	if (_list.size() == _n)
		throw NoMoreNumber();
	_list.push_back(x);
}
// sort du plus petit au plus grand, puis trouver premier min 
// et enfin faire une boucle et remplacer le min si le min_temporaire est plus petit
unsigned int Span::shortestSpan()
{
	int min;
	int	current;
	int min_temp;

	if (_list.size() < 2)
		throw NotEnoughNumbers();
	_list.sort();
	std::list<int>::iterator it = _list.begin();
	current = *it;
	it++;
	min = *it - current;
	while (it != _list.end())
	{
		min_temp = *it - current;
		current = *it;
		if (min_temp < min)
			min = min_temp;
		it++;
	}
	return (static_cast<unsigned int>(min));
}

unsigned int Span::longestSpan()
{
	int min = *std::min_element(_list.begin(), _list.end());
	int max = *std::max_element(_list.begin(), _list.end());

	return (static_cast<unsigned int>(max) - static_cast<unsigned int>(min));
}

std::list<int>::iterator Span::begin()
{
	return (_list.begin());
}
std::list<int>::iterator Span::end()
{
	return (_list.end());
}

const char *Span::NoMoreNumber::what() const throw()
{
	return ("Cannot add any more numbers");
}

const char *Span::NotEnoughNumbers::what() const throw()
{
	return ("Need more numbers");
}