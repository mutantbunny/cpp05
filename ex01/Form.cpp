/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:01:34 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/07 00:35:33 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : m_grade_to_sign(150), m_grade_to_execute(1),
	m_is_signed(false), m_name("Unnamed") { }

Form::Form(int grade_to_sign, int grade_to_execute) :m_is_signed(false),
m_name("Unnamed")
{
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();

	m_grade_to_sign = grade_to_sign;
	m_grade_to_execute = grade_to_execute;
}

Form::Form(std::string name, int grade_to_sign,
	int grade_to_execute) : m_is_signed(false), m_name(name)
{
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();

	m_grade_to_sign = grade_to_sign;
	m_grade_to_execute = grade_to_execute;

}

Form::Form(Form &src) : m_is_signed(src.m_is_signed), m_name(src.m_name)
{
	if (src.m_grade_to_sign > 150 || src.m_grade_to_execute > 150)
		throw Form::GradeTooLowException();
	else if (src.m_grade_to_sign < 1 || src.m_grade_to_execute < 1)
		throw Form::GradeTooHighException();

	m_grade_to_sign = src.m_grade_to_sign;
	m_grade_to_execute = src.m_grade_to_execute;
}

Form::~Form(void) { }

Form &Form::operator=(Form &src)
{
	if (this == &src)
		return *this;

	if (src.m_grade_to_sign > 150 || src.m_grade_to_execute > 150)
		throw Form::GradeTooLowException();
	else if (src.m_grade_to_sign < 1 || src.m_grade_to_execute < 1)
		throw Form::GradeTooHighException();

	m_grade_to_sign = src.m_grade_to_sign;
	m_grade_to_execute = src.m_grade_to_execute;
	m_is_signed = src.m_is_signed;
	return *this;
}

int Form::getGradeToSign() const { return m_grade_to_sign; }

int Form::getGradeToExecute() const { return m_grade_to_execute; }

bool Form::getIsSigned() const { return m_is_signed; }

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > m_grade_to_sign)
		throw Form::GradeTooLowException();
	m_is_signed = true;
}

std::string Form::getName() const { return m_name; }

Form::GradeTooHighException::GradeTooHighException(void) { }

Form::GradeTooHighException::
	GradeTooHighException(const GradeTooHighException &src) { (void)src; }

Form::GradeTooHighException::~GradeTooHighException(void) throw () { }

Form::GradeTooHighException &Form::GradeTooHighException::
	operator=(const GradeTooHighException &src)
{
	(void)src;
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high!";
}

Form::GradeTooLowException::GradeTooLowException(void) { }

Form::GradeTooLowException::
	GradeTooLowException(const GradeTooLowException &src) { (void)src; }

Form::GradeTooLowException::~GradeTooLowException(void) throw () { }

Form::GradeTooLowException &Form::GradeTooLowException::
	operator=(const GradeTooLowException &src)
{
	(void)src;
	return *this;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
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
