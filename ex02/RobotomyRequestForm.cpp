/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:30:04 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/07 03:46:22 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", "Unknown target", 72, 45, false)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", target, 72, 45, false)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src)
	: AForm("RobotomyRequestForm", src.getTarget(), src.getGradeToSign(),
		src.getGradeToExecute(), src.getIsSigned()) { }

RobotomyRequestForm::~RobotomyRequestForm(void) { }

RobotomyRequestForm
	&RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
	if (this == &src)
		return *this;

	setTarget(src.getTarget());
	setGradeToSign(src.getGradeToSign());
	setGradeToExecute(src.getGradeToExecute());
	setIsSigned(src.getIsSigned());

	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	if (!getIsSigned())
		throw AForm::FormNotSignedException();

	std::cout << "Bzzz... Bzzz... Bzzz..." << std::endl;

	if (rand() % 2)
	{
		std::cout << getTarget()
		<< " has been robotomized successfully!" << std::endl;
	}
	else
		std::cout << "Robotomy Failed!" << std::endl;
}