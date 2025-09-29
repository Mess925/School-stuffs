/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:58:02 by hthant            #+#    #+#             */
/*   Updated: 2025/08/29 21:11:44 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>
# include "Form.hpp"

class Form;

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
		void	signForm(Form& f);

		class GradeTooHighException : public std::exception {
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
				const char* what() const throw();
		};
};

// std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);

# endif
