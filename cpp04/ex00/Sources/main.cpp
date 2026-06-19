/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:56:35 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 16:28:20 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Animal.hpp"
#include "../Includes/Cat.hpp"
#include "../Includes/Dog.hpp"
#include "../Includes/WrongAnimal.hpp"
#include "../Includes/WrongCat.hpp"

int main()
{
	std::cout << YELLOW  "-----CLASS CREATION-----\n" RESET;
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	j->getType();
	i->getType();
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	
	/* ********************************************************* */
	std::cout << YELLOW  "-----DEEP COPIES-----\n" RESET;
	Animal x;
	Animal y(x);
	Animal z;

	z = x;
	
	std::cout << std::endl;

	/* ********************************************************* */
	std::cout << YELLOW  "-----WRONG CLASS CREATION-----\n" RESET;
	const WrongAnimal	*wrong = new WrongAnimal();
	const WrongAnimal	*cat = new WrongCat();

	cat->getType();
	wrong->makeSound();
	cat->makeSound();


	std::cout << std::endl;
	/* ********************************************************* */
	std::cout << YELLOW  "-----CLASS DESTRUCTION-----\n" RESET;
	delete cat, delete wrong;
	delete i;
	delete j;
	delete meta;
	std::cout << std::endl;
	
	return (0);
}