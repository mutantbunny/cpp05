/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:01:34 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/07 00:35:33 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : m_grade_to_sign(150), m_grade_to_execute(1),
	m_is_signed(false), m_target("Unknown target"), m_name("Unnamed") { }

AForm::AForm(int grade_to_sign, int grade_to_execute) : m_is_signed(false),
m_target("Unknown target"), m_name("Unnamed")
{
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();

	m_grade_to_sign = grade_to_sign;
	m_grade_to_execute = grade_to_execute;
}

AForm::AForm(std::string name, std::string target, int grade_to_sign,
	int grade_to_execute, bool is_signed) : m_is_signed(is_signed),
		m_target(target), m_name(name)
{
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();

	m_grade_to_sign = grade_to_sign;
	m_grade_to_execute = grade_to_execute;

}

AForm::AForm(AForm &src) : m_is_signed(src.m_is_signed), m_target(src.m_target),
		m_name(src.m_name)
{
	if (src.m_grade_to_sign > 150 || src.m_grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	else if (src.m_grade_to_sign < 1 || src.m_grade_to_execute < 1)
		throw AForm::GradeTooHighException();

	m_grade_to_sign = src.m_grade_to_sign;
	m_grade_to_execute = src.m_grade_to_execute;
}

AForm::~AForm(void) { }

AForm &AForm::operator=(AForm &src)
{
	if (this == &src)
		return *this;

	if (src.m_grade_to_sign > 150 || src.m_grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	else if (src.m_grade_to_sign < 1 || src.m_grade_to_execute < 1)
		throw AForm::GradeTooHighException();

	m_grade_to_sign = src.m_grade_to_sign;
	m_grade_to_execute = src.m_grade_to_execute;
	m_is_signed = src.m_is_signed;
	m_target = src.m_target;

	return *this;
}

void AForm::setGradeToSign(int new_grade) { m_grade_to_sign = new_grade; }

void AForm::setGradeToExecute(int new_grade) { m_grade_to_execute = new_grade; }

void AForm::setIsSigned(bool new_is_signed) { m_is_signed = new_is_signed; }

void AForm::setTarget(std::string new_target) { m_target = new_target; }

int AForm::getGradeToSign() const { return m_grade_to_sign; }

int AForm::getGradeToExecute() const { return m_grade_to_execute; }

bool AForm::getIsSigned() const { return m_is_signed; }

std::string AForm::getName() const { return m_name; }

std::string AForm::getTarget() const { return m_target; }

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > m_grade_to_sign)
		throw AForm::GradeTooLowException();
	m_is_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << ", ";

	if (form.getIsSigned())
		out << "form is signed";
	else
		out << "form is not signed";

	out << ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExecute() << '.';

	return out;
}
