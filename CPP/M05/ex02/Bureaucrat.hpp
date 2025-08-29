/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:58:02 by hthant            #+#    #+#             */
/*   Updated: 2025/08/30 00:22:22 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat 
{	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~ Bureaucrat();

		Bureaucrat(const std::string _name, int _grade);

		int getGrade() const;
		const std::string& getName() const;

		void	increaseGrade();
		void	decreaseGrade();
		void	signForm(AForm& f);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw(){
					return "Grade is to High";
				}		
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw(){
					return "Grade is too Low";
			}
		};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);

# endif
