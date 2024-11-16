/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:45:15 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 19:26:16 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
 		AForm();
		AForm(const AForm &src);
		AForm(const std::string name, int signGrade, int executeGrade);
		virtual ~AForm();
		AForm  &operator=(const AForm &src);
		const std::string	getName() const;
		bool  getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void  beSigned(const Bureaucrat &bureaucrat);
		void  execute(const Bureaucrat &executor) const;
		virtual void performAction() const = 0;

		/* Exception classes */
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;
};

std::ostream &operator<<(std::ostream &os , const AForm &src);

#endif
