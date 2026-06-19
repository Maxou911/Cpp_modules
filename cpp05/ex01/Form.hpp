/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:42:49 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/12 13:48:10 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_sign;
		const int			_grade_exec;
	
	public:
		Form();
		Form(const std::string &name, const int _grade_sign, const int _grade_exec);
		Form(const Form &copy);
		Form &operator=(const Form &other);
		~Form();

		const std::string	getName() const;
		bool				getSignature() const;
		int					getGradeSignature() const;
		int					getGradeExecution() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		void	beSigned(const Bureaucrat &b);

};

std::ostream &operator<<(std::ostream &out, const Form &f);