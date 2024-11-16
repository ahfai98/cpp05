/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:46:36 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 19:32:05 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

/* Default constructor function of Form class */
Form::Form() : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150)
{}

/* Copy constructor function of Form class */
Form::Form(const Form &src): _name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	*this = src;
}

/* Constructor function for (string, int, int) input of Form class */
Form::Form(const std::string name, int signGrade, int executeGrade) :_name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (this->_signGrade < 1 || this->_executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->_signGrade > 150 || this->_executeGrade > 150)
		throw Form::GradeTooLowException();
}

/* Destructor function of Form class */
Form::~Form()
{}

/* Copy assignation operator of Form class */
Form &Form::operator=(const Form &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

/* Getter function for name of Form class */
const std::string	Form::getName() const
{
	return (this->_name);
}

/* Getter function for signed of Form class */
bool	Form::getSigned() const
{
	return (this->_signed);
}

/* Getter function for signGrade of Form class */
int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

/* Getter function for executeGrade of Form class */
int	Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

/* Exception function for when Grade is too high */
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("(Form) GradeTooHighException was called.");
}

/* Exception function for when Grade is too low */
const char	*Form::GradeTooLowException::what() const throw()
{
	return ("(Form) GradeTooLowException was called.");
}

/* Function when << operator is called. */
std::ostream &operator<<(std::ostream &os, const Form &src)
{
	os << "Form name: " << src.getName() << std::endl;
	if (src.getSigned())
		os << "Signed: Yes"<< std::endl;
	else
		os << "Signed: No" << std::endl;
	os << "Grade to sign: " << src.getSignGrade() << std::endl;
	os << "Grade to execute: " << src.getExecuteGrade() << std::endl;
	return (os);
}
