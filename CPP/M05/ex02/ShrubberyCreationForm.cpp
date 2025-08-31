/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 01:03:09 by hthant            #+#    #+#             */
/*   Updated: 2025/08/31 20:04:22 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("ShrubberyCreation",145,137), _target("default target"){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:AForm(other), _target(other._target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this!= &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:AForm("ShrubberyCreation",145,137), _target(target){}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	checkExecution(executor);
	std::ofstream ofs((_target + "_shrubbery").c_str());
	ofs << "   ^   \n  /|\\  \n //|\\\\ \n   |   \n";
}
