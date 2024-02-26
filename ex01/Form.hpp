/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:01:32 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/26 01:19:31 by gmachado         ###   ########.fr       */
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
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif