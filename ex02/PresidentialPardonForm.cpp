/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:21:01 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/26 19:59:54 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("PresidentialPardonForm", "Unknown target",
		MIN_SIGN_GRADE, MIN_EXEC_GRADE, false) { }

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", target,
		MIN_SIGN_GRADE, MIN_EXEC_GRADE, false) { }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src)
	: AForm("PresidentialPardonForm", src.getTarget(), src.getGradeToSign(),
		src.getGradeToExecute(), src.getIsSigned()) { }

PresidentialPardonForm::~PresidentialPardonForm(void) { }

PresidentialPardonForm
	&PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
	if (this == &src)
		return *this;

	setTarget(src.getTarget());
	setIsSigned(src.getIsSigned());

	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	if (!getIsSigned())
		throw AForm::FormNotSignedException();

	std::cout << getTarget()
		<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}