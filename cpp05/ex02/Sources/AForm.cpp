/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:44:29 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/09 17:28:57 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AForm.hpp"

AForm::AForm() : _name("default"), _is_signed(false), _grade_sign(10), _grade_exec(10) {}
AForm::AForm(const std::string &name, int grade_sign, int grade_exec) : _name(name), _is_signed(false), 
_grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_exec < 1 || grade_sign < 1)
		throw GradeTooHighException();
	if (grade_exec > 150 || grade_sign > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &copy) : _name(copy._name), _grade_sign(copy._grade_sign),
 _grade_exec(copy._grade_exec)
{
	this->_is_signed = copy._is_signed;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return (*this);
}


const std::string	AForm::getName() const {return this->_name;}
bool				AForm::getSignature() const {return this->_is_signed;}
int					AForm::getGradeSignature() const {return this->_grade_sign;}
int					AForm::getGradeExecution() const {return this->_grade_exec;}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low\n");
}

const char *AForm::FormUnsigned::what() const throw()
{
	return ("Form has not been signed\n");
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _grade_sign)
		throw GradeTooLowException();
	_is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName() << " is " << std::boolalpha << f.getSignature() << " it needs "
	<< f.getGradeSignature() << " to be signed and " << f.getGradeExecution()
	<< " to be executed.\n";
	return (out);
}