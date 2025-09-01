/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:06:35 by hthant            #+#    #+#             */
/*   Updated: 2025/09/01 18:16:14 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Create an intern
        Intern someRandomIntern;

        // Create bureaucrats
        Bureaucrat boss("Boss", 1);
        Bureaucrat junior("Junior", 150);

        // Intern makes forms
        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm* robo = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur");
        AForm* invalid = someRandomIntern.makeForm("unknown form", "Nobody");

        std::cout << "\n--- Signing and executing forms ---\n" << std::endl;

        // Boss can sign and execute
        if (shrub) {
            boss.signForm(*shrub);
            boss.executeForm(*shrub);
        }

        if (robo) {
            boss.signForm(*robo);
            boss.executeForm(*robo);
        }

        if (pardon) {
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
        }

        std::cout << "\n--- Junior tries to sign and execute ---\n" << std::endl;

        if (shrub) {
            junior.signForm(*shrub);
            junior.executeForm(*shrub);
        }

        // Clean up
        delete shrub;
        delete robo;
        delete pardon;
        delete invalid; // should be nullptr if invalid

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

