/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/07 22:56:20 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

/* ShrubberyCreationForm: Sign: 145, Execute: 137
** RobotomyRequestForm: Sign 72, Execute: 45
** PresidentialPardonForm: Sign 25, Execute: 5 */
int main()
{
	Bureaucrat				dumbBureaucrat("Dumb", 150);
	Bureaucrat				averageBureaucrat("Average", 70);
	Bureaucrat				aboveAverageBureaucrat("AboveAverage", 30);
	Bureaucrat				smartBureaucrat("Smart", 1);
	ShrubberyCreationForm	shrubbery("Home");
	RobotomyRequestForm 	robotomy("Ricky");
	PresidentialPardonForm	presidential("Ivan");

	std::cout << "\n---------- EX02 Shrubbery Test ----------\n" << std::endl;
	dumbBureaucrat.signForm(shrubbery);
	dumbBureaucrat.executeForm(shrubbery);
	averageBureaucrat.signForm(shrubbery);
	//averageBureaucrat.executeForm(shrubbery);
	aboveAverageBureaucrat.signForm(shrubbery);
	//aboveAverageBureaucrat.executeForm(shrubbery);
	smartBureaucrat.signForm(shrubbery);
	//smartBureaucrat.executeForm(shrubbery);

	std::cout << "\n---------- EX02 Robotomy Test ----------\n" << std::endl;
	srand(time(NULL));
	dumbBureaucrat.signForm(robotomy);
	dumbBureaucrat.executeForm(robotomy);
	averageBureaucrat.signForm(robotomy);
	averageBureaucrat.executeForm(robotomy);
	aboveAverageBureaucrat.signForm(robotomy);
	aboveAverageBureaucrat.executeForm(robotomy);
	smartBureaucrat.signForm(robotomy);
	smartBureaucrat.executeForm(robotomy);

	std::cout << "\n---------- EX02 Presidential Test ----------\n" << std::endl;
	dumbBureaucrat.signForm(presidential);
	dumbBureaucrat.executeForm(presidential);
	averageBureaucrat.signForm(presidential);
	averageBureaucrat.executeForm(presidential);
	aboveAverageBureaucrat.signForm(presidential);
	aboveAverageBureaucrat.executeForm(presidential);
	smartBureaucrat.signForm(presidential);
	smartBureaucrat.executeForm(presidential);

	return (0);
}