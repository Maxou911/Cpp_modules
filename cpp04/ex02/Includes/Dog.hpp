/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:30:04 by maalwis           #+#    #+#             */
/*   Updated: 2025/11/28 18:45:09 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <ostream>

#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &other);
		~Dog();
		
		void				setIdeas(int i,const std::string ideas);
		const std::string	getIdeas(int index) const;
		void				makeSound() const;
};

#endif