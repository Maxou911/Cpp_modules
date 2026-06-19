/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:47:43 by maalwis           #+#    #+#             */
/*   Updated: 2025/12/05 17:10:44 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

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

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();

		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif