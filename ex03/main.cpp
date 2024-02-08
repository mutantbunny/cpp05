/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:56:00 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/08 04:57:43 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
	Intern intern;
	AForm *form;

	try
	{
		form = intern.makeForm("robotomy request", "Johann");
		std::cout << "Created form: " << *form << '\n' << std::endl;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Failed to create robotomy request form. Exception: "
			<<e.what() << '\n' << std::endl;
	}

	try
	{
		form = intern.makeForm("presidential pardon", "Klaus");
		std::cout << "Created form: " << *form << '\n' << std::endl;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Failed to create presidential pardon form. Exception: "
			<<e.what() << '\n' << std::endl;
	}

	try
	{
		form = intern.makeForm("shrubbery creation", "Paul");
		std::cout << "Created form: " << *form << '\n' << std::endl;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Failed to create shrubbery creation form. Exception: "
			<<e.what() << '\n' << std::endl;
	}

	try
	{
		form = intern.makeForm("random request", "Paul");
	}
	catch (std::exception &e)
	{
		std::cout << "Failed to create random request form. Exception: "
			<<e.what() << '\n' << std::endl;
	}

	std::cout << std::endl;
}
