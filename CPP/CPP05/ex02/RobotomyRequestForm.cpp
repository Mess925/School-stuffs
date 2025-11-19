/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:45:45 by hthant            #+#    #+#             */
/*   Updated: 2025/08/31 20:12:07 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    :AForm("RobotomyRequest",72,45), _target("default target"){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    :AForm(other), _target(other._target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if(this != &other){
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm("RobotomyRequest",72,45), _target(target){}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	checkExecution(executor);
	std::cout << "Drilling Noises" <<std::endl;
	static bool seeded = false;
	if(!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	if(std::rand() % 2)
		std::cout<< _target << "has been robotomized successfully" <<std::endl;
	else
		std::cout << "Robotomy failed on " << _target << " ." << std::endl;
}
