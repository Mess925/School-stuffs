/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:22:51 by hthant            #+#    #+#             */
/*   Updated: 2025/08/30 01:02:51 by hthant           ###   ########.fr       */
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
		~AForm();

		AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);

		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw(){
					return "AForm Grade is too high!";
				}
		};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw(){
					return "AForm Grade is too low!";
				}
		};
		void	beSigned(const Bureaucrat &b);

		const	std::string getName() const;
		bool	getIsSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
};

std::ostream& operator<<(std::ostream &os, const AForm &f);

# endif
