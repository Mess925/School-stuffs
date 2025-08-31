/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 01:05:07 by hthant            #+#    #+#             */
/*   Updated: 2025/08/31 13:24:27 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);
		void	execute(Bureaucrat const &executor) const override;		
}

# endif

