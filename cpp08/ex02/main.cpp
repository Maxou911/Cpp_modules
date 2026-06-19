/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:35:27 by maalwis           #+#    #+#             */
/*   Updated: 2026/03/17 16:39:21 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Stack == LIFO --> LAST IN FIRST OUT
int main()
{
	std::cout << ORANGE "TEST MAIN NORMAL:\n" RESET;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl; // doit retourner 17
	mstack.pop(); // supprime la premiere valeur en partant du haut == 17
	std::cout << mstack.size() << std::endl; // doit retourner 1
	// pile ==> 5
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	// pile ==> 5 3 5 737 0
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << ORANGE "TEST CONST:\n" RESET;
	const MutantStack<int> &constStack = mstack;

	for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
		std::cout << *it << std::endl;
/* ********************************************************************* */

	std::cout << ORANGE "TEST CONTENEUR VECTOR:\n" RESET;
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(17);
	std::cout << vec.back() << std::endl;
	vec.pop_back();
	std::cout << vec.size() << std::endl;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	vec.push_back(0);
	std::vector<int>::iterator vec_it = vec.begin();
	std::vector<int>::iterator vec_ite = vec.end();
	++vec_it;
	--vec_it;
	while (vec_it != vec_ite)
	{
		std::cout << *vec_it << std::endl;
		++vec_it;
	}
	std::vector<int> vec_2(vec);
/* ********************************************************************* */

	std::cout << ORANGE "TEST CONTENEUR LIST:\n" RESET;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator list_it = list.begin();
	std::list<int>::iterator list_ite = list.end();
	++list_it;
	--list_it;
	while (list_it != list_ite)
	{
		std::cout << *list_it << std::endl;
		++list_it;
	}
	std::list<int> list_2(list);
/* ********************************************************************* */

	std::cout << ORANGE "TEST CONTENEUR DEQUE:\n" RESET;
	std::deque<int> deque;
	deque.push_back(5);
	deque.push_back(17);
	std::cout << deque.back() << std::endl;
	deque.pop_back();
	std::cout << deque.size() << std::endl;
	deque.push_back(3);
	deque.push_back(5);
	deque.push_back(737);
	deque.push_back(0);
	std::deque<int>::iterator deque_it = deque.begin();
	std::deque<int>::iterator deque_ite = deque.end();
	++deque_it;
	--deque_it;
	while (deque_it != deque_ite)
	{
		std::cout << *deque_it << std::endl;
		++deque_it;
	}
	std::deque<int> deque_2(deque);
	return 0;
}