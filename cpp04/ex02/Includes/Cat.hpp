/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:30:01 by maalwis           #+#    #+#             */
/*   Updated: 2025/11/28 18:45:05 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <ostream>

#include "A_Animal.hpp"
#include "Brain.hpp"

class Cat : public A_Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &rhs);
		~Cat();
		
		void				setIdeas(int i,const std::string ideas);
		const std::string	getIdeas(int index) const;
		void				makeSound() const;
};

#endif