/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:31:39 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 19:48:47 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

/* Default constructor function of ShrubberyCreationForm class */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("NULL")
{}

/* Copy constructor function of ShrubberyCreationForm class */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	*this = src;
}

/* Constructor function for string input of ShrubberyCreationForm class */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{}

/* Destructor function of ShrubberyCreationForm class */
ShrubberyCreationForm::~ShrubberyCreationForm()
{	}

/* Copy assignation operator function of ShrubberyCreationForm class */
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

/* PerformAction function to draw a Shrubbery tree to a file in the directory*/
void	ShrubberyCreationForm::performAction() const
{
	std::ofstream	out_file((this->_target + "_shrubbery").c_str());

	out_file << "Three trees: " << std::endl;
	out_file << " _" << std::endl;
	out_file << "| |" << std::endl;                
	out_file << "| |_ _ __ ___  ___" << std::endl; 
	out_file << "| __| '__/ _ \\/ _ \\" << std::endl;
	out_file << "| |_| | |  __/  __/" << std::endl;
	out_file << " \\__|_|  \\___|\\___|" << std::endl;
	out_file << std::endl;
	out_file << " _" << std::endl;
	out_file << "| |" << std::endl;                
	out_file << "| |_ _ __ ___  ___" << std::endl; 
	out_file << "| __| '__/ _ \\/ _ \\" << std::endl;
	out_file << "| |_| | |  __/  __/" << std::endl;
	out_file << " \\__|_|  \\___|\\___|" << std::endl;
	out_file << std::endl;
	out_file << " _" << std::endl;
	out_file << "| |" << std::endl;                
	out_file << "| |_ _ __ ___  ___" << std::endl; 
	out_file << "| __| '__/ _ \\/ _ \\" << std::endl;
	out_file << "| |_| | |  __/  __/" << std::endl;
	out_file << " \\__|_|  \\___|\\___|" << std::endl;
}