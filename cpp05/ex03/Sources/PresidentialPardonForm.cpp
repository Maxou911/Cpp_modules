/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:37:22 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/12 18:27:37 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("President", 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("President", 25, 5), _target(copy._target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string	PresidentialPardonForm::getTarget() const {return _target;}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignature())
		throw FormUnsigned();
	else if (executor.getGrade() > this->getGradeExecution())
		throw GradeTooLowException();
	else
		std::cout << this->getTarget() << BLUEISH " has been pardoned by Zaphod Beeblebrox\n" RESET;
}