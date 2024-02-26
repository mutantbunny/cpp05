/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:55:57 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/26 01:16:31 by gmachado         ###   ########.fr       */
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
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
