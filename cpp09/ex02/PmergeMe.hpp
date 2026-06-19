/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:48:43 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/23 18:00:52 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cstdlib>

# define PURPLE "\e[0;35m"
# define BOLDPURPLE "\e[1;35m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define ORANGE "\e[0;38;5;202m\002"
# define BLUEISH "\e[1;38;5;111m\002"
# define PINK "\e[38;5;217m\002"
# define CYAN "\e[0;36m"
# define RESET "\e[0m"

typedef std::allocator<int> alloc;

// NOTE CI-DESSOUS
// C<int, alloc> == std::vector<int, std::allocator<int>> ou std::deque<int, std::allocator<int>>
// std::vector<int, std::allocator<int>> pareil que std::vector<int> car compilateur reconnait

template <template <typename, typename> class C>
class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &other);

		size_t				Jacobsthal(size_t n);
		void				binarySearchInsert(C<int, alloc> &cont, int value);
		C<int, alloc>		fordJohnson(C<int, alloc> &cont);
		void				insertPend(C<int, alloc> &mainChain, C<int, alloc> &pend);
};
bool	parse(char **av, std::vector<int> &vec, std::deque<int> &deq);

#include "PmergeMe.tpp"
