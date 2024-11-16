/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 19:05:13 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n---------- EX00 First Test ----------\n" << std::endl;
	try
    {
        Bureaucrat bur_ex("Bureaucrat1", 1);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bur_ex("Bureaucrat2", 150);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "\n---------- EX00 Second Test ----------\n" << std::endl;
	try
    {
        Bureaucrat bur_ex("Bureaucrat3", 0);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bur_ex("Bureaucrat4", 151);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bur_ex("Bureaucrat5", 1);
        bur_ex.becomeHigherGrade();
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bur_ex("Bureaucrat6", 150);
        bur_ex.becomeLowerGrade();
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	Bureaucrat b("John", 50);
	std::cout << b << std::endl;
}