/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:30:04 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/26 20:06:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", "Unknown target",
		MIN_SIGN_GRADE, MIN_EXEC_GRADE, false)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", target,
		MIN_SIGN_GRADE, MIN_EXEC_GRADE, false)
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