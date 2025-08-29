/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:53:34 by hthant            #+#    #+#             */
/*   Updated: 2025/08/29 20:04:02 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void){
	try {
		Bureaucrat	b("tayza", 150);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	b("tayza", 150);
		b.increaseGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	b("tayza", 1);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	b("tayza", 1);
		b.decreaseGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	f("form1", false, 1, 1);
		Bureaucrat b("tayza", 2);
		b.signForm(f);
		// std::cout << "isSigned: " << f.getIsSigned() << std::endl;
		// std::cout << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	f("form1", false, 150, 1);
		Bureaucrat b("tayza", 1);
		b.signForm(f);
		// std::cout << "isSigned: " << f.getIsSigned() << std::endl;
		// std::cout << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
