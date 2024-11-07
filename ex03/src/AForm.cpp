/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:46:36 by jyap              #+#    #+#             */
/*   Updated: 2024/11/07 23:14:16 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

/* Default constructor function of Form class */
AForm::AForm() : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150)
{ 
}

/* Copy constructor function of Form class */
AForm::AForm(const AForm &src) :
	_name(src._name), _signed(src._signed), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
}

/* Constructor function for (string, int, int) input of Form class */
AForm::AForm(const std::string name, int signGrade, int executeGrade) :
	_name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (this->_signGrade < 1 || this->_executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (this->_signGrade > 150 || this->_executeGrade > 150)
		throw AForm::GradeTooLowException();
}

/* Destructor function of Form class */
AForm::~AForm()
{
}

/* Copy assignation operator of Form class */
AForm	&AForm::operator=(const AForm &src)
{
	if (this == &src)
		return (*this);
	this->_signed = src._signed;
	return (*this);
}

/* Getter function for name of Form class */
const std::string	AForm::getName() const
{
	return (this->_name);
}

/* Getter function for signed of Form class */
bool	AForm::getSigned() const
{
	return (this->_signed);
}

/* Getter function for signGrade of Form class */
int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

/* Getter function for executeGrade of Form class */
int	AForm::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->_executeGrade)
		throw AForm::GradeTooLowException();
	if (this->_signed == false)
		throw AForm::FormNotSigned();
	performAction();
}

/* Exception function for when Grade is too high */
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("(AForm) GradeTooHighException was called.");
}

/* Exception function for when Grade is too low */
const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("(AForm) GradeTooLowException was called.");
}

const char	*AForm::FormNotSigned::what() const throw()
{
	return ("(AForm) FormNotSigned was called.");
}

/* Function when << operator is called. */
std::ostream	&operator<<(std::ostream &os, const AForm &src)
{
	os << "Form name: " << src.getName() << std::endl;
	os << "Signed: " << src.getSigned() << std::endl;
	os << "Grade to sign: " << src.getSignGrade() << std::endl;
	os << "Grade to execute: " << src.getExecuteGrade() << std::endl;
	return (os);
}