/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:58:02 by hthant            #+#    #+#             */
/*   Updated: 2025/08/28 09:58:04 by hthant           ###   ########.fr       */
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
		std::string& getName() const;

		void increaseGrade();
		void decreaseGrade();

		class GradeTooHighException : public std::exception {
			private:
				const std::string _message;
			public:
				GradeTooHighException(const std::string& message) : _message(message)
			{
				const char* what() const throw() {
					return _message.c_str();
				}
			}
		}
}

# endif
