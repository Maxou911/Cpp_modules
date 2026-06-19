/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:35:34 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/13 14:02:19 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();

		AForm	*makePres(const std::string &target);
		AForm	*makeRobot(const std::string &target);
		AForm	*makeShrub(const std::string &target);
		
		AForm	*makeForm(const std::string &name, const std::string &target);
};