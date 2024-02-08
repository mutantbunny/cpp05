/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:56:00 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/08 03:50:05 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void run_test(AForm &form, Bureaucrat &buro, int test_num)
{
	try
	{
		std::cout << "\n*** Run Test #" << test_num << " ***\n\nBureaucrat: "
			<< buro << "\nForm: " << form << "\nExecute Form:" << std::endl;
		buro.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception while executing " << form.getName() << ": "
			<< e.what() << std::endl;
	}

	try
	{
		std::cout << "Sign form:" << std::endl;
		buro.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception while signing " << form.getName() << ": "
			<< e.what() << std::endl;
	}

	try
	{
		std::cout << "Execute Form:" << std::endl;
		buro.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception while executing " << form.getName() << ": "
			<< e.what() << std::endl;
	}

	std::cout << "\n*** End of test #" << test_num << " ***\n" << std::endl;
}

int main(void)
{
	int test_num = 0;
	RobotomyRequestForm rr_form("Bob");
	PresidentialPardonForm pp_form;
	ShrubberyCreationForm sc_form("Joe");

	// RobotomyRequestForm tests

	Bureaucrat rr_buro_1("Ivan", RobotomyRequestForm::MIN_SIGN_GRADE + 1);
	Bureaucrat rr_buro_2("Vladmir", RobotomyRequestForm::MIN_EXEC_GRADE + 1);

	run_test(rr_form, rr_buro_1, ++test_num);
	rr_buro_1.incrementGrade();
	run_test(rr_form, rr_buro_1, ++test_num);

	run_test(rr_form, rr_buro_2, ++test_num);
	rr_buro_2.incrementGrade();
	run_test(rr_form, rr_buro_2, ++test_num);

	std::cout << "\n*** Run test #" << ++test_num << " ***\n\nBureaucrat: "
			<< rr_buro_2 << "\nForm: " << rr_form
			<< "\nTest randomness of robotomy outcome:\n" << std::endl;

	for (int i = 1; i <= 10; ++i)
	{
		std::cout << "Execute Robotomy Request Form (run #"
			<< i << "):" << std::endl;
		rr_buro_2.executeForm(rr_form);
		std::cout << std::endl;
	}
	std::cout << "*** End of test #" << test_num << " ***\n" << std::endl;

	// PresidentialPardonForm tests

	Bureaucrat pp_buro_1("Boris", PresidentialPardonForm::MIN_SIGN_GRADE + 1);
	Bureaucrat pp_buro_2("Katya", PresidentialPardonForm::MIN_EXEC_GRADE + 1);

	run_test(pp_form, pp_buro_1, ++test_num);
	pp_buro_1.incrementGrade();
	run_test(pp_form, pp_buro_1, ++test_num);

	run_test(pp_form, pp_buro_2, ++test_num);
	pp_buro_1.incrementGrade();
	run_test(pp_form, pp_buro_2, ++test_num);

	// PresidentialPardonForm tests

	Bureaucrat sc_buro_1("Martina", ShrubberyCreationForm::MIN_SIGN_GRADE + 1);
	Bureaucrat sc_buro_2("Oleg", ShrubberyCreationForm::MIN_EXEC_GRADE + 1);

	run_test(sc_form, sc_buro_1, ++test_num);
	sc_buro_1.incrementGrade();
	run_test(sc_form, sc_buro_1, ++test_num);

	run_test(sc_form, sc_buro_2, ++test_num);
	sc_buro_2.incrementGrade();
	run_test(sc_form, sc_buro_2, ++test_num);
}
