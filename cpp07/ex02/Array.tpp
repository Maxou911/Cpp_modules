/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:39:51 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/21 14:06:45 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	_n = 0;
	_array = NULL;
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete[] _array;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_n = n;
	_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
	_n = copy._n;
	_array = new T[_n];
	for (unsigned int i = 0; i < _n ; i++)
		_array[i] = copy._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		if (_array)
			delete[] _array;
		_n = other._n;
		_array = new T[_n];
		for (unsigned int i = 0; i < _n ; i++)
			_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_n);
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _n)
		throw IndexOutOfRange();
	return (_array[index]);
}

/* template <typename T>
T& Array<T>::operator[](size_t index) const
{
	if (index >= _n)
		throw IndexOutOfRange();
	return (_array[index]);
} */

template <typename T>
const char *Array<T>::IndexOutOfRange::what() const throw()
{
	return ("Index out of range\n");
}
