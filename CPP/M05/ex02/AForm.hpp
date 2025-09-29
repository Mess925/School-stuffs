/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:22:51 by hthant            #+#    #+#             */
/*   Updated: 2025/08/31 19:45:15 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_gradeToSign;
		const int		_gradeToExecute;
	public:
		AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		AForm(std::string name, int gradeToSign, int gradeToExecute);

		class	GradeTooHighException : public std::exception{
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception{
				const char* what() const throw();
		};
		class	FormNotSignedException : public	std::exception{
				const char* what() const throw();
		};	

		const	std::string	getName() const;
		bool	getIsSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;

		virtual	void	execute(Bureaucrat const &executor) const = 0;
		void	beSigned(const Bureaucrat &b);
		void	checkExecution(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream &os, const AForm &f);

# endif
