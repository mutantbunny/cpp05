/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:55:57 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/06 02:39:37 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string m_name;
		int m_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat &src);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);

		~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat &src);

		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		std::string getName() const;
		void signForm(Form &f);

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
