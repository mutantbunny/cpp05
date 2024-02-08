/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:50:18 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/08 02:22:18 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		ShrubberyCreationForm(std::string target);

		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(ShrubberyCreationForm &src);

		virtual void execute(Bureaucrat const &executor) const;

		static const int MIN_SIGN_GRADE = 145;
		static const int MIN_EXEC_GRADE = 137;
};

#endif
