/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:12:01 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/26 20:12:19 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

static AForm *create_pp_form(std::string target)
{
	return new PresidentialPardonForm(target);
}

static AForm *create_rr_form(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm *create_sc_form(std::string target)
{
	return new ShrubberyCreationForm(target);
}

const t_form_type Intern::VALID_FORMS[NUM_VALID_FORMS] =
		{
			{ .form_name = "presidential pardon", .create_fn = create_pp_form},
			{ .form_name = "robotomy request", .create_fn = create_rr_form},
			{ .form_name = "shrubbery creation", .create_fn = create_sc_form}
		};

Intern::Intern(void) { }

Intern::Intern(Intern &src) { (void)src; }


Intern::~Intern(void) { }

Intern &Intern::operator=(Intern &src)
{
	(void)src;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	for (int i = 0; i < NUM_VALID_FORMS; ++i)
	{
		if (name == VALID_FORMS[i].form_name)
		{
			std::cout << "Intern creates " << name << " form." << std::endl;
			return VALID_FORMS[i].create_fn(target);
		}
	}
	std::cout << "There is no form named " << name << "." << std::endl;
	return NULL;
}