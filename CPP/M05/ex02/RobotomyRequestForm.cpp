/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:45:45 by hthant            #+#    #+#             */
/*   Updated: 2025/08/30 18:15:50 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    :AForm("RobotomyRequest",72,45), _target("default target"){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    :AForm(other), _target(other._target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)

}