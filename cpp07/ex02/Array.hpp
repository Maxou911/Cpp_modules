/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:39:59 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/21 14:06:36 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

template <typename T> class Array
{
	private:
		T				*_array;
		unsigned int	_n;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &copy);
		Array &operator=(const Array<T> &other);
		~Array();

		unsigned int	size() const;
		T& operator[](size_t index);
		// T& operator[](size_t index) const;

		class IndexOutOfRange : public  std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


#include "Array.tpp"
