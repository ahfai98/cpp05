/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:58:39 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 19:40:44 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}


Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

/* Getter function for name of Bureaucrat class */
const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

/* Getter function for grade of Bureaucrat class */
int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/* Increments the grade of the Bureaucrat (grade--) */
void	Bureaucrat::becomeHigherGrade()
{
	try
	{
		if (this->_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	this->_grade--;
}

/* Decrements the grade of the Bureaucrat (grade++) */
void	Bureaucrat::becomeLowerGrade()
{
	try
	{
		if (this->_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	this->_grade++;
}

/* Exception function for when Grade is too high */
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("(Bureaucrat) GradeTooHighException was called.");
}

/* Exception function for when Grade is too low */
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("(Bureaucrat) GradeTooLowException was called.");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", Bureaucrat Grade " << b.getGrade() << "." << std::endl;
	return (os);
}
