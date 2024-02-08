/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:55:53 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/08 03:42:42 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

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

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << m_name << " signed " << f.getName() << '.' << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << m_name << " couldn't sign " << f.getName()
			<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << m_name << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

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
	return "Grade is too high!";
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
	return "grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << '.';
	return out;
}