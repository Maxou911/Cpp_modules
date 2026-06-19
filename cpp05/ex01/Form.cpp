/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:44:29 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/12 13:48:01 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _is_signed(false), _grade_sign(10), _grade_exec(10) {}
Form::Form(const std::string &name, int grade_sign, int grade_exec) : _name(name), _is_signed(false), 
_grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_exec < 1 || grade_sign < 1)
		throw GradeTooHighException();
	if (grade_exec > 150 || grade_sign > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &copy) : _name(copy._name), _grade_sign(copy._grade_sign),
 _grade_exec(copy._grade_exec)
{
	this->_is_signed = copy._is_signed;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return (*this);
}


const std::string	Form::getName() const {return this->_name;}
bool				Form::getSignature() const {return this->_is_signed;}
int					Form::getGradeSignature() const {return this->_grade_sign;}
int					Form::getGradeExecution() const {return this->_grade_exec;}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low\n");
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _grade_sign)
		throw GradeTooLowException();
	_is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName() << " is " << std::boolalpha << f.getSignature() << " it needs "
	<< f.getGradeSignature() << " to be signed and " << f.getGradeExecution()
	<< " to be executed.\n";
	return (out);
}