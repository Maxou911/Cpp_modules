/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:25:41 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/17 16:39:32 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <vector>
#include <list>

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

template <typename T> class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &other);
		
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

};

#include "MutantStack.tpp"
