/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:58:39 by jyap              #+#    #+#             */
/*   Updated: 2024/11/07 21:07:39 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Default constructor function of Bureaucrat class */
Bureaucrat::Bureaucrat() : _name("Default")
{
	this->_grade = 150;
}

/* Constructor function for string and int input 0f Bureaucrat class */
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

/* Copy constructor function of Bureaucrat class */
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
}

/* Destructor function of Bureaucrat class */
Bureaucrat::~Bureaucrat()
{
}

/* Copy assignation operator of Bureaucrat class */
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this == &src)
		return (*this);
	this->_grade = src._grade;
	return (*this);
}

/* Getter function for name of Bureaucrat class */
const std::string	Bureaucrat::getName()
{
	return (this->_name);
}

/* Getter function for grade of Bureaucrat class */
int	Bureaucrat::getGrade()
{
	return (this->_grade);
}

/* Increments the grade of the Bureaucrat (grade--) */
void	Bureaucrat::becomeSmarter()
{
	try
	{
		if (this->_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
	}
	this->_grade--;
}

/* Decrements the grade of the Bureaucrat (grade++) */
void	Bureaucrat::becomeDumber()
{
	try
	{
		if (this->_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
	}
	this->_grade++;
}

/* Exception function for when Grade is too high */
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("(Bureaucrat) GradeTooHighException was called");
}

/* Exception function for when Grade is too low */
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("(Bureaucrat) GradeTooLowException was called");
}