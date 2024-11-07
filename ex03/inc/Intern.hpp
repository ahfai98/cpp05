/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:04:36 by jyap              #+#    #+#             */
/*   Updated: 2024/11/07 23:05:00 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define MAX_FORMS 3

class Intern
{
	public:
		/* Orthrodox canonical form */
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern	&operator=(const Intern &src);

		/* Member functions */
		AForm	*makeForm(const std::string formName, const std::string target);

		/* Exception classes */
		class InvalidFormNameException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif