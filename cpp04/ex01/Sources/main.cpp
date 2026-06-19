/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:56:35 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 16:28:40 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Animal.hpp"
#include "../Includes/Brain.hpp"
#include "../Includes/Cat.hpp"
#include "../Includes/Dog.hpp"

int main()
{
	const Animal *meta[5];

	std::cout << YELLOW  "-----CLASS CREATION-----\n" RESET;
	for(int x = 0; x < 5; x++)
	{
		if (x % 2 == 0) 
			meta[x] = new Dog();
		else
			meta[x] = new Cat();
		meta[x]->getType();
		meta[x]->makeSound();
	}
	std::cout << std::endl;
	/* ********************************************************* */
	std::cout << YELLOW  "-----DEEP COPIES-----\n" RESET;

	Dog dog;
	Dog copy_dog1(dog);
	Dog copy_dog2;

	copy_dog2 = dog;

	std::cout << std::endl;
	/* ********************************************************* */
	std::cout << YELLOW  "-----IDEAS TESTS-----\n" RESET;
	Cat *cat[1];
	int	i = 0;

	cat[i] =  new Cat();
	cat[i]->setIdeas(10, "Cat is drinking milk");
	cat[i]->setIdeas(2, "Cat is napping");
	cat[i]->setIdeas(99, "Cat is thinking");
	cat[i]->setIdeas(100, "Cerr");

	std::cout << cat[i]->getIdeas(10) << std::endl;
	std::cout << cat[i]->getIdeas(2) << std::endl;
	std::cout << cat[i]->getIdeas(99) << std::endl;
	std::cout << cat[i]->getIdeas(5) << std::endl;
	std::cout << cat[i]->getIdeas(100) << std::endl;
	
	std::cout << std::endl;
	/* ********************************************************* */
	std::cout << YELLOW  "-----CLASS DESTRUCTION-----\n" RESET;
	delete (cat[i]);
	for(int x = 0; x < 5; x++)
		delete (meta[x]);
	return (0);
}


