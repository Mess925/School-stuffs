/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:22:51 by hthant            #+#    #+#             */
/*   Updated: 2025/08/29 20:38:16 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_gradeToSign;
		const int		_gradeToExecute;
	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);

		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw(){
					return "Form Grade is too high!";
				}
		};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw(){
					return "Form Grade is too low!";
				}
		};
		void	beSigned(const Bureaucrat &b);

		const	std::string getName() const;
		bool	getIsSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
};

std::ostream& operator<<(std::ostream &os, const Form &f);

# endif
