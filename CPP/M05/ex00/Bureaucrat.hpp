/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 21:15:22 by hthant            #+#    #+#             */
/*   Updated: 2025/08/28 01:02:47 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
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

		Bureaucrat(std::string _name, int _grade);

		int getGrade() const;
		std::string& getName() const;

		void increaseGrade();
		void decreaseGrade();
}

# endif
