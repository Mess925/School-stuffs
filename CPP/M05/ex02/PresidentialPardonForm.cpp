/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 01:02:57 by hthant            #+#    #+#             */
/*   Updated: 2025/08/30 18:15:38 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp" 

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentalPardon",25,5), _target("default target"){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target){}

PresidentialPardonForm &PresidentailPardonForm::operator=(const PresidentialPardonForm &other)
{
	if( this!= &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm",25,5), _target(target){}
