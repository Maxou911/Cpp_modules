/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:48:46 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/23 17:59:51 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <template <typename, typename> class C>
PmergeMe<C>::PmergeMe() {}

template <template <typename, typename> class C>
PmergeMe<C>::~PmergeMe() {}

template <template <typename, typename> class C>
PmergeMe<C>::PmergeMe(const PmergeMe<C> &copy)
{
	(void)copy;
}
template <template <typename, typename> class C>
PmergeMe<C> &PmergeMe<C>::operator=(const PmergeMe<C> &other)
{
	(void)other;
	return *this;
}

// A Inserer dans la fonction fordJohnson juste avant la recursivite
	// std::cout << YELLOW "Pairs:" RESET << std::endl;
	// for (size_t i = 0; i < pair.size(); i++)
	// 	std::cout << pair[i].first << "," << pair[i].second << " | ";

	// std::cout << std::endl;
	// std::cout << YELLOW "Pend:" RESET;
	// for (size_t i = 0; i < pend.size(); i++)
	// 	std::cout << " " << pend[i];
	// std::cout << std::endl;

	// std::cout << YELLOW "MainChain:" RESET;
	// for (size_t i = 0; i < mainChain.size(); i++)
	// 	std::cout << " " << mainChain[i];
	// std::cout << std::endl;

void	swap(int &a, int &b)
{
	int c;

	c = a;
	a = b;
	b = c;
}

//	  Main algo
//		|	|
//		V	V
//	Separate the array in pairs and sort the pairs, 
//	Example :	12, 32, 44, 21, 42, 41, 99
// --->	PAIRS : [12, 32] [21, 44] [41, 42] 99
//	Put lowest in pend and higer in mainChain; if odd, insert last number in pend
// --->	PEND :	12, 21, 41 99	mainChain : 32 44 42
//	Then recursive on mainChain :
// --->	PAIRS : [32, 44] 42
// --->	PEND :	32, 42			mainChain : 44
//	Then insertPend function
//			|	|
//			V	V
//	Insert pend[0] at beginning of mainChain
// --->	PEND :	42			mainChain : 32, 44
//	Then insert rest of pend with Jacobsthal and binarySearch
//	Look insertPend() function for continuation...
template <template <typename, typename> class C>
C<int, std::allocator<int> >	PmergeMe<C>::fordJohnson(C<int, alloc> &container)
{
	C<std::pair<int, int>, std::allocator<int> > pair;
	C<int, std::allocator<int> > mainChain;
	C<int, std::allocator<int> > pend;

	if (container.size() <= 1)
		return container;
	int first, second, last;
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		first = container[i];
		second = container[i + 1];
		if (first > second)
			swap(first, second);
		pair.push_back(std::make_pair(first, second));
		pend.push_back(first);
		mainChain.push_back(second);
	}
	if (container.size() % 2 != 0)
	{
		last = container.back();
		pend.push_back(last);
	}
	mainChain = fordJohnson(mainChain);
	insertPend(mainChain, pend);
	return (mainChain);
}

// Divide the search space into two halves by finding the middle index "mid". 
// Compare the middle of the search space with the key. 
// If the key is found at middle, the process is terminated.
// If the key is not found at middle, choose which half will be used as the next search space.
// -> If the key is smaller than the middle, then the left side is used for next search.
// -> If the key is larger than the middle, then the right side is used for next search.
template <template <typename, typename> class C>
void	PmergeMe<C>::binarySearchInsert(C<int, alloc> &container, int value)
{
	int	low = 0;
	int	high = container.size() - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (container[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	container.insert(container.begin() + low, value);
}

// Current = previous + 2 x (previous of the previous)
// Starting with 0 and 1 (these are fixed), the sequence progresses as follows:
// The next number is: 1 + 2 × 0 = 1 So, the sequence becomes: 0, 1, 1.
// After that: 1 + 2 × 1 = 3 The sequence is now: 0, 1, 1, 3.
// After that: 3 + 2 × 1 = 5 The sequence is now: 0, 1, 1, 3, 5.
// After that: 5 + 2 × 3 = 11 The sequence is now: 0, 1, 1, 3, 5, 11.
template <template <typename, typename> class C>
size_t PmergeMe<C>::Jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}
// Insert pend[0] at beginning of mainChain
// Insert pend in the mainchain with jacobsthal suite and binarysearch
// In this order : 
// 1
// 3 2
// 5 4
// 11 10 9 8 7 6
template <template <typename, typename> class C>
void PmergeMe<C>::insertPend(C<int, alloc> &mainChain, C<int, alloc> &pend)
{
	mainChain.insert(mainChain.begin(), pend[0]);

	size_t k = 2;
	while (Jacobsthal(k - 1) < pend.size())
	{
		size_t curr = Jacobsthal(k);
		size_t prev = Jacobsthal(k - 1);
		if (curr > pend.size())
			curr = pend.size();
		while (curr > prev)
		{
			binarySearchInsert(mainChain, pend[curr - 1]);
			curr--;
		}
		k++;
	}
}

bool	is_duplicate(std::vector<int> &vec, int num)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] == num)
			return true;
	}
	return false;
}
bool	is_number(char *av)
{
	for (size_t i = 0; av[i]; i++)
	{
		if (av[i] < '0' || av[i] > '9')
			return false;
	}
	return true;
}
bool	parse(char **av, std::vector<int> &vec, std::deque<int> &deq)
{
	int i = 1;
	while (av[i])
	{
		if (!is_number(av[i]))
		{
			std::cout << RED "Error " RESET ": Please put only positive numbers\n";
			return false;
		}
		char* endptr;
		long val = std::strtol(av[i], &endptr, 10);
		if (*endptr != '\0' || val < 0 || val > INT_MAX)
		{
			std::cout << RED "Error " RESET ": Please do not exceed INT_MAX\n";
			return false;
		}
		int num = static_cast<int>(val);
		if (is_duplicate(vec, num))
		{
			std::cout << RED "Error " RESET ": Please do not put any duplicate numbers\n";
			return false;
		}
		vec.push_back(num);
		deq.push_back(num);
		i++;
	}
	return true;
}
