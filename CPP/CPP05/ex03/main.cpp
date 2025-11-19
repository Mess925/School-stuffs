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

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <exception>
#include <execution>

int main() {
    try {
        Intern someRandomIntern;

        Bureaucrat boss("Boss", 1);
        Bureaucrat junior("Junior", 150);

        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm* robo = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur");
        AForm* invalid = someRandomIntern.makeForm("unknown form", "Nobody");

        std::cout << "\n--- Signing and executing forms ---\n" << std::endl;

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

        std::cout << "\n--- JuniorB tries to sign and execute ---\n" << std::endl;

	Bureaucrat juniorB("JuniorB", 1);

        if (shrub) {
		juniorB.signForm(*shrub);
		juniorB.executeForm(*shrub);
        }

	if(robo){
		juniorB.signForm(*robo);
		juniorB.executeForm(*robo);
	}
	if(pardon){
		juniorB.signForm(*pardon);
		juniorB.executeForm(*pardon);
	}
	std::cout << "\n--- Junior tries to sign and execute ---\n"<< std::endl;
        if (shrub) {
		junior.signForm(*shrub);
		junior.executeForm(*shrub);
        }

	if(robo){
		junior.signForm(*robo);
		junior.executeForm(*robo);
	}
	if(pardon){
		junior.signForm(*pardon);
		junior.executeForm(*pardon);
	}

	std::cout << "\n----------- Clean Up ---------------" << std::endl << std::endl;
        delete shrub;
        delete robo;
        delete pardon;
        delete invalid;
    }
    catch (std::exception &e) {
        	std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "------------------- Subject ------------------\n";
    try{
	    Intern intern2;
	    AForm *rrf;
	    rrf = intern2.makeForm("robotomy request", "Bender");
    }
    catch(const std::exception& e){
	    std::cout << e.what() << std::endl;
    }

    return 0;
}

