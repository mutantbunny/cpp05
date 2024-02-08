/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:50:18 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/08 02:20:56 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <stdlib.h>
#include <time.h>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &src);

		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(RobotomyRequestForm &src);

		virtual void execute(Bureaucrat const &executor) const;

		static const int MIN_SIGN_GRADE = 72;
		static const int MIN_EXEC_GRADE = 45;
};

#endif
