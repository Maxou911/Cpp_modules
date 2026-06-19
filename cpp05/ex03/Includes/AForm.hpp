/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:42:49 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/09 17:55:27 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_sign;
		const int			_grade_exec;
	
	public:
		AForm();
		AForm(const std::string &name, const int _grade_sign, const int _grade_exec);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

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

		class FormUnsigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator<<(std::ostream &out, const AForm &f);