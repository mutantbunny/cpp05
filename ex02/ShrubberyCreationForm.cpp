/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:00:09 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/07 03:46:35 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", "Unknown target", 145, 137, false) { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", target, 145, 137, false) { }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src)
	: AForm("ShrubberyCreationForm", src.getTarget(), src.getGradeToSign(),
		src.getGradeToExecute(), src.getIsSigned()) { }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

ShrubberyCreationForm
	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &src)
{
	if (this == &src)
		return *this;

	setTarget(src.getTarget());
	setGradeToSign(src.getGradeToSign());
	setGradeToExecute(src.getGradeToExecute());
	setIsSigned(src.getIsSigned());

	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	if (!getIsSigned())
		throw AForm::FormNotSignedException();

	std::string filename(getTarget() + "_shrubbery");
	std::ofstream target_file(filename);

	target_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	target_file << "                  /\\\n";
	target_file << "    /\\           /__\\           /\\\n";
	target_file << "   /__\\         /____\\         /__\\\n";
	target_file << "  /____\\       /______\\       /____\\\n";
	target_file << " /______\\     /________\\     /______\\\n";
	target_file << "/________\\   /__________\\   /________\\\n";
	target_file << "   |__|          |__|          |__|\n";
}