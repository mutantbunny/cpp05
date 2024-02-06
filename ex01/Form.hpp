/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:01:32 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/06 03:13:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		int m_grade_to_sign;
		int m_grade_to_execute;
		bool m_is_signed;
		const std::string m_name;

	public:
		Form(void);
		Form(Form &src);
		Form(int grade_to_sign, int grade_to_execute);
		Form(std::string name, int grade_to_sign, int grade_to_execute);

		~Form(void);

		Form &operator=(Form &src);

		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		std::string getName() const;
		void beSigned(Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void);
				GradeTooHighException(const GradeTooHighException &src);
				virtual ~GradeTooHighException(void) throw ();
				GradeTooHighException
					&operator=(const GradeTooHighException &src);
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void);
				GradeTooLowException(const GradeTooLowException &src);
				virtual ~GradeTooLowException(void) throw ();
				GradeTooLowException
					&operator=(const GradeTooLowException &src);
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif