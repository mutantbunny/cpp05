/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:55:53 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/06 01:36:42 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : m_name("Unnamed"), m_grade(150) { }

Bureaucrat::Bureaucrat(int grade) : m_name("Unnamed")
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	m_grade = grade;

}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	m_grade = grade;

}

Bureaucrat::Bureaucrat(Bureaucrat &src) : m_name(src.m_name)
{
	if (src.m_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (src.m_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	m_grade = src.m_grade;
}

Bureaucrat::~Bureaucrat(void) { }

Bureaucrat &Bureaucrat::operator=(Bureaucrat &src)
{
	if (this == &src)
		return *this;

	if (src.m_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (src.m_grade < 1)
		throw Bureaucrat::GradeTooHighException();

	m_grade = src.m_grade;
	return *this;
}

int Bureaucrat::getGrade() const { return m_grade; }

void Bureaucrat::incrementGrade()
{
	if (m_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	--m_grade;
}

void Bureaucrat::decrementGrade()
{
	if (m_grade >=150)
		throw Bureaucrat::GradeTooLowException();
	++m_grade;
}

std::string Bureaucrat::getName() const { return m_name; }

Bureaucrat::GradeTooHighException::GradeTooHighException(void) { }

Bureaucrat::GradeTooHighException::
	GradeTooHighException(const GradeTooHighException &src) { (void)src; }

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw () { }

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::
	operator=(const GradeTooHighException &src)
{
	(void)src;
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) { }

Bureaucrat::GradeTooLowException::
	GradeTooLowException(const GradeTooLowException &src) { (void)src; }

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw () { }

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::
	operator=(const GradeTooLowException &src)
{
	(void)src;
	return *this;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << '.';
	return out;
}
