/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:01:32 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/06 03:13:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		int m_grade_to_sign;
		int m_grade_to_execute;
		bool m_is_signed;
		std::string m_target;
		const std::string m_name;

	protected:
		void setGradeToSign(int new_grade);
		void setGradeToExecute(int new_grade);
		void setIsSigned(bool new_is_signed);
		void setTarget(std::string new_target);

	public:
		AForm(void);
		AForm(AForm &src);
		AForm(int grade_to_sign, int grade_to_execute);
		AForm(std::string name, std::string target, int grade_to_sign,
			int grade_to_execute, bool is_signed);

		virtual ~AForm(void);

		AForm &operator=(AForm &src);

		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		std::string getName() const;
		std::string getTarget() const;
		void beSigned(Bureaucrat &b);

		virtual void execute(Bureaucrat const &executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif