/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:05:20 by jyap              #+#    #+#             */
/*   Updated: 2024/11/07 23:15:52 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

/* Default constructor function of Intern class */
Intern::Intern()
{
}

/* Copy constructor function of Intern class */
Intern::Intern(const Intern &src)
{
	(void)src;
}

/* Destructor function of Intern class */
Intern::~Intern()
{
}

/* Copy assignation operator function of Intern class */
Intern	&Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

/* MakeForm function to make forms using string name and target input */
AForm	*Intern::makeForm(const std::string formName, const std::string target)
{
	const std::string	availableName[MAX_FORMS]
		= {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	AForm				*availableForm[MAX_FORMS]
		= {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	AForm				*selectedForm;

	selectedForm = NULL;
	for (int i = 0; i < MAX_FORMS; i++)
	{
		if (formName == availableName[i])
		{
			std::cout << "Intern creates " << formName << "Form" << std::endl;
			selectedForm = availableForm[i];
		}
		else
			delete (availableForm[i]);
	}
	if (selectedForm == NULL)
		throw Intern::InvalidFormNameException();
	return (selectedForm);
}

/* Exception function for when the Form name is invalid */
const char	*Intern::InvalidFormNameException::what() const throw()
{
	return ("(Intern) InvalidFormNameException was called.");
}