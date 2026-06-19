/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:29:52 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/15 16:34:49 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

#include <iostream>
#include <ostream>

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

class A_Animal
{
	protected:
		std::string _type;
		A_Animal(const std::string &type);
	public:
		A_Animal();
		A_Animal(const A_Animal &copy);
		A_Animal &operator=(const A_Animal &other);
		virtual ~A_Animal();
		
		
		virtual void	makeSound() const = 0;
		const std::string	getType() const;
};

#endif