/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 19:22:10 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    std::cout << "\n---------- EX01 First Test ----------\n" << std::endl;
	Bureaucrat b("bureaucrat", 70);
	Form lowForm("lowForm", 100, 100);
	Form highForm("highForm", 30, 30);

	std::cout << b << std::endl;
	b.becomeLowerGrade();
	std::cout << b << std::endl;
	b.becomeHigherGrade();
	std::cout << b << std::endl;
	std::cout << lowForm << std::endl;
	std::cout << highForm << std::endl;
	b.signForm(lowForm);
	b.signForm(highForm);
	std::cout << lowForm << std::endl;
	std::cout << highForm << std::endl;
	return (0);
}