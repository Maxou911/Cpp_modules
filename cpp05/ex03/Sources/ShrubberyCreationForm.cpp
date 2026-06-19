/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:37:18 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/12 18:27:41 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137), _target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("Shrubbery", 145, 137), _target(copy._target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string	ShrubberyCreationForm::getTarget() const {return _target;}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignature())
		throw FormUnsigned();
	else if (executor.getGrade() > this->getGradeExecution())
		throw GradeTooLowException();
	else
	{
		std::string outfileName = this->getTarget() + "_shrubbery";
		std::ofstream outfile(outfileName.c_str());
		if (!outfile) {
			std::cerr << ".replace outfile didn't create\n";
			return ;
		}
		
		outfile <<"  ***********************\n"
		<< " **************************\n"
		<< "*****************************\n"
		<< " **************************\n"
		<< "  ***********************\n"
		<< "          ********\n"
		<< "          ********\n"
		<< "          ********\n"
		<< "          ********\n"
		<< "          ********\n";
		outfile.close();
	}
}