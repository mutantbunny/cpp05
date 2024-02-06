/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:56:00 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/06 03:02:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat std_bc;
	std::cout << "Created Bureaucrat: " << std_bc << std::endl;
	std::cout << "\n***\n" << std::endl;

	try
	{
		Bureaucrat unnamed_bc(10);
		std::cout << "Created Bureaucrat: " << unnamed_bc << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create unnamed Bureaucrat with grade 10."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Bureaucrat jonas("Jonas", 50);
		std::cout << "Created Bureaucrat: " << jonas << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Bureaucrat named Jonas with grade 50."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Bureaucrat tim("Tim", 0);
		std::cout << "Created Bureaucrat: " << tim << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Bureaucrat named Tim with grade 0."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Bureaucrat mauro("Mauro", 1);
		std::cout << "Created Bureaucrat: " << mauro << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Bureaucrat named Mauro with grade 1."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Bureaucrat luzia("Luzia", 150);
		std::cout << "Created Bureaucrat: " << luzia << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Bureaucrat named Luzia with grade 150."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Bureaucrat dora("Dora", 151);
		std::cout << "Created Bureaucrat: " << dora << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Bureaucrat named Dora with grade 151."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Bureaucrat maria("Maria", 1);
		std::cout << "Created Bureaucrat: " << maria << std::endl;
		maria = std_bc;
		std::cout << "Copied unnamed bureaucrat grade to Maria. "
			<< "New status of Maria: " << maria << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to copy unnamed bureaucrat grade to Maria."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Bureaucrat pablo("Pablo", 1);
		std::cout << "Created Bureaucrat: " << pablo << std::endl;
		pablo.decrementGrade();
		std::cout << "Decremented Pablo's grade. "
			<< "New status of Pablo: " << pablo << std::endl;
		pablo.incrementGrade();
		std::cout << "Incremented Pablo's grade. "
			<< "New status of Pablo: " << pablo << std::endl;
		pablo.incrementGrade();
		std::cout << "Incremented Pablo's grade again. "
			<< "New status of Pablo: " << pablo << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Bureaucrat Pablo or change his grade."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Bureaucrat arlindo("Arlindo", 150);
		std::cout << "Created Bureaucrat: " << arlindo << std::endl;
		arlindo.incrementGrade();
		std::cout << "Incremented Arlindo's grade. "
			<< "New status of Arlindo: " << arlindo << std::endl;
		arlindo.decrementGrade();
		std::cout << "Decremented Arlindo's grade. "
			<< "New status of Arlindo: " << arlindo << std::endl;
		arlindo.decrementGrade();
		std::cout << "Decremented Arlindo's grade again. "
			<< "New status of Arlindo: " << arlindo << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Bureaucrat Arlindo or change his grade."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;
}
