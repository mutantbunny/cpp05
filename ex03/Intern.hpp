/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 04:01:12 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/26 20:11:05 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef struct s_form_type
{
	std::string form_name;
	AForm* (*create_fn)(std::string target);
} t_form_type;

class Intern
{
	private:
		static const int NUM_VALID_FORMS = 3;
		static const t_form_type VALID_FORMS[NUM_VALID_FORMS];

	public:
		Intern(void);
		Intern(Intern &src);

		~Intern(void);

		Intern &operator=(Intern &src);

		AForm* makeForm(std::string name, std::string target);
};

#endif