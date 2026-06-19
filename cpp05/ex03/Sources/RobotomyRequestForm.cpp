/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:36:21 by maalwis           #+#    #+#             */
/*   Updated: 2026/01/09 17:36:22 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("Robotomy", 72, 45), _target(copy._target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string	RobotomyRequestForm::getTarget() const {return _target;}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignature())
		throw FormUnsigned();
	else if (executor.getGrade() > this->getGradeExecution())
		throw GradeTooLowException();
	else
	{
		int	randomNumber = rand();

		std::cout <<  BLUEISH "Makes some drilling noises..." << this->getTarget() << RESET;
		if ((randomNumber % 2) == 0)
			std::cout << BLUEISH " has been robotomized\n" RESET;
		else
			std::cout << RED " Robotomization has failed !\n" RESET;
	}
}