/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:58:02 by hthant            #+#    #+#             */
/*   Updated: 2025/08/29 12:16:13 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

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

		void increaseGrade();
		void decreaseGrade();

		class GradeTooHighException : public std::exception
		{
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat b);

# endif
