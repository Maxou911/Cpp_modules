/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:53:18 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/15 12:10:03 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	init_data(Data *data)
{
	data->_age = 50;
	data->_name = "Bob";
	data->_place = "Glasgow";
}
int	main(void)
{
	Serializer s;
	Data	data;
	init_data(&data);

	std::cout << YELLOW "Before Serialization:\n" RESET;
	std::cout << "Age: "<< data._age << std::endl;
	std::cout << "Name: "<< data._name << std::endl;
	std::cout << "Place: "<< data._place << std::endl;
	std::cout << RED << &data << RESET << std::endl;
	std::cout << std::endl;

	uintptr_t x = s.serialize(&data);

	std::cout << std::endl;
	std::cout << YELLOW "After Serialization:\n" RESET;
	std::cout << "Age: "<< data._age << std::endl;
	std::cout << "Name: "<< data._name << std::endl;
	std::cout << "Place: "<<data._place << std::endl;
	std::cout << RED << std::hex << x << RESET<< std::endl;

	std::cout << std::endl;
	std::cout << RED << &data << RESET << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "After Deserialization:\n" RESET;
	std::cout << "Age: "<< std::dec << data._age << std::endl;
	std::cout << "Name: "<< data._name << std::endl;
	std::cout << "Place: "<<data._place << std::endl;
	std::cout << PURPLE << s.deserialize(x) << RESET << std::endl;
	std::cout << RED << &data << RESET<< std::endl;
}
