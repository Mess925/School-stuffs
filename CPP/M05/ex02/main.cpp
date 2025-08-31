/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:43:59 by hthant            #+#    #+#             */
/*   Updated: 2025/08/31 19:44:03 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main() {
    srand(time(NULL));

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

