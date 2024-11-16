/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:25:22 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 19:48:07 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

/* Default constructor function of RobotomyRequestForm class */
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Null")
{}

/* Copy constructor function of RobotomyRequestForm class */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	*this = src;
}

/* Constructor function for string input of RobotomyRequestForm class */
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

/* Destructor function of RobotomyRequestForm class */
RobotomyRequestForm::~RobotomyRequestForm()
{}

/* Copy assignation operator function of RobotomyRequestForm class */
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

/* PerformAction function to have a 50% chance of robotomize the target */
void	RobotomyRequestForm::performAction() const
{
	std::cout << "* Drilling noises... *" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->_target << "'s robotomy was successful!" << std::endl;
	else
		std::cout << this->_target << "'s robotomy has failed." << std::endl;
}
