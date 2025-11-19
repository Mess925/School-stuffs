/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:43:59 by hthant            #+#    #+#             */
/*   Updated: 2025/09/01 13:23:26 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <exception>
#include <iostream>

int main()
{
    srand(time(NULL));

    try{
	    Bureaucrat bob("Bob", 1);
	    ShrubberyCreationForm shrub("home");
	    RobotomyRequestForm robo("Bender");
	    PresidentialPardonForm pardon("Arthur");

	    bob.signForm(shrub);
	    bob.executeForm(shrub);

	    bob.signForm(robo);
	    bob.executeForm(robo);

	    bob.signForm(pardon);
	    bob.executeForm(pardon);
    }
    catch(const std::exception& e){
	    std::cout << e.what() << std::endl; 
    }
    std::cout << "-------------------------------------------------------------" <<std::endl;
    try{
	   Bureaucrat a("a", 150);
	   ShrubberyCreationForm shrub("hello");
	   RobotomyRequestForm robo("Robo");
	   PresidentialPardonForm pardon("Pre");

	   a.signForm(shrub);
	   a.executeForm(shrub);

	   a.signForm(robo);
	   a.executeForm(robo);

	   a.signForm(pardon);
	   a.executeForm(pardon);
    }
    catch(const std::exception& e){
    	std::cout << e.what() <<std::endl;
    }
    /*
    try{
	    AForm a;
    }
    catch(const std::exception& e)
    {
	    std::cout << e.what() <<std::endl;
    }*/
}
