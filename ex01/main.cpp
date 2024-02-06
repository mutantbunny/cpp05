/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:56:00 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/06 03:10:05 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
	Form std_form;
	std::cout << "Created Form: " << std_form << std::endl;
	std::cout << "\n***\n" << std::endl;

	try
	{
		Form unnamed_bc(10, 30);
		std::cout << "Created Form: " << unnamed_bc << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create unnamed Form with grade 10 required "
			<< "to sign and grade 30 required to execute."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Form a1("A1", 50, 90);
		std::cout << "Created Form: " << a1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Form A1 with grade 50 required "
			<< "to sign and grade 90 required to execute."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Form a1("B2", 0, 90);
		std::cout << "Created Form: " << a1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Form B2 with grade 0 required "
			<< "to sign and grade 90 required to execute."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Form a1("C3", 150, 0);
		std::cout << "Created Form: " << a1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Form C3 with grade 150 required "
			<< "to sign and grade 0 required to execute."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n***\n" << std::endl;

	try
	{
		Form a1("D4", 151, 1);
		std::cout << "Created Form: " << a1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Form D4 with grade 151 required "
			<< "to sign and grade 1 required to execute."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Form a1("E5", 1, 151);
		std::cout << "Created Form: " << a1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Form E5 with grade 1 required "
			<< "to sign and grade 151 required to execute."
			<< std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n***\n" << std::endl;

	try
	{
		Form f6("F6", 30, 40);
		std::cout << "Created Form: " << f6 << std::endl;
		f6 = std_form;
		std::cout << "Copied unnamed form grades and signature status to f6. "
			<< "New status of F6: " << f6 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to copy unnamed form grades and "
			<< "signature status to F6." << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n***\n" << std::endl;

	Bureaucrat mario("Mario", 50);
	Form g7("G7", 49, 10);
	Form h8("H8", 50, 20);

	std::cout << "Before signing forms." << std::endl;
	std::cout << "Created Bureaucrat: " << mario << std::endl;
	std::cout << "Created Form: " << g7 << std::endl;
	std::cout << "Created Form: " << h8 << std::endl;

	try
	{
		mario.signForm(g7);
	}
	catch (std::exception &e)
	{
		std::cerr << "Bureucrat Mario failed to sign form G7." << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		mario.signForm(h8);
	}
	catch (std::exception &e)
	{
		std::cerr << "Bureucrat Mario failed to sign form H8." << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "After signing forms." << std::endl;
	std::cout << "Status of Form G7: " << g7 << std::endl;
	std::cout << "Status of Form H8: " << h8 << std::endl;

	std::cout << "\n***\n" << std::endl;
}
