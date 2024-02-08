/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:50:18 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/08 02:20:29 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm &src);
		PresidentialPardonForm(std::string target);

		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(PresidentialPardonForm &src);

		virtual void execute(Bureaucrat const &executor) const;

		static const int MIN_SIGN_GRADE = 25;
		static const int MIN_EXEC_GRADE = 5;
};

#endif
