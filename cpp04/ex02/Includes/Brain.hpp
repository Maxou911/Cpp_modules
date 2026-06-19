/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:29:57 by maalwis           #+#    #+#             */
/*   Updated: 2025/11/28 18:42:00 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <ostream>

#include "A_Animal.hpp"

class Brain
{
	protected:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &rhs);
		~Brain();
		
		void				setIdeas(int i,const std::string ideas);
		const std::string	getIdeas(int index) const;
		
};

#endif