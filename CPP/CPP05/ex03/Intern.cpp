/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:54:44 by hthant            #+#    #+#             */
/*   Updated: 2025/09/01 12:42:10 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){
	(void) other;
};

Intern &Intern::operator=(const Intern& other)
{
	(void) other;
	return *this;
}

Intern::~Intern(){}

int Intern::getFormIndex(const std::string &formName){
	std::string forms[3] = {"shrubbery creation","presidential pardon","robotomy request"};
	for(int i = 0; i < 3; i++){
		if(forms[i] == formName)
			return i;
	}
	return -1;
}

AForm* Intern::createForm(const std::string &formName, const std::string &target){
	int index = getFormIndex(formName);

	switch(index){
		case 0:
			return(new ShrubberyCreationForm(target));
		case 1:
			return(new PresidentialPardonForm(target));
		case 2:
			return(new RobotomyRequestForm(target));
		default:
			return NULL;
	}
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target){
	AForm* form = createForm(formName, target);

	std::cout << (form ? "Intern creates " + formName + " ." : "Error: Form " + formName + " does not exist.") << std::endl;
	return form;
}
