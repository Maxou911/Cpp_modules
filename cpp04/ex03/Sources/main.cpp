/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:06:06 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/17 13:11:55 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/H.hpp"

int main()
{
	std::cout << YELLOW  "-----MAIN DU SUJET-----\n" RESET;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << BLUE << "Modifying original inventory..." << RESET << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
/* **************************************************************** */
	std::cout << YELLOW << "-----DEEP COPIES-----\n" << RESET;

	Character original("original");
	original.equip(new Ice());
	original.equip(new Cure());
	
	Character copy(original);	// appel du copy constructor
	Character copy2 = original;	// appel de l'assignment operator

	std::cout << BLUE << "Using original:" << RESET << std::endl;
	original.use(0, original);	// doit appeler ice
	original.use(1, original);	// doit appeler cure

	std::cout << BLUE << "Using copy:" << RESET << std::endl;
	copy.use(0, copy);			// doit aussi appeler ice
	copy.use(1, copy);			// doit aussi appeler cure

	std::cout << BLUE << "Using copy2:" << RESET << std::endl;
	copy2.use(0, copy);			// doit aussi appeler ice
	copy2.use(1, copy);			// doit aussi appeler cure
	
	std::cout << BLUE << "Modifying original inventory..." << RESET << std::endl;
	original.unequip(1);

	std::cout << "original :";
	original.use(1, original);	// ne doit rien faire
	std::cout << std::endl;
	
	std::cout << "copy :";
	copy.use(1, original);		// doit toujours utiliser ice
	
	std::cout << "copy2 :";
	copy2.use(1, original);		// doit toujours utiliser ice
	std::cout << std::endl;

/* **************************************************************** */
	
	std::cout << YELLOW << "-----COPY MATERIA SOURCE-----\n" << RESET;

	MateriaSource ms1;
	ms1.learnMateria(new Ice());
	ms1.learnMateria(new Cure());

	MateriaSource ms2 = ms1;	// operator assignment
	MateriaSource ms3(ms1);		// constructor copy

	AMateria* cp1 = ms1.createMateria("ice");
	AMateria* cp2 = ms2.createMateria("ice");
	AMateria* cp3 = ms3.createMateria("cure");

	std::cout << "ms1 ice ptr: " << cp1 << std::endl;
	std::cout << "ms2 ice ptr: " << cp2 << std::endl;
	std::cout << "ms3 ice ptr: " << cp3 << std::endl;

	delete cp1;
	delete cp2;
	delete cp3;

	return (0);
}