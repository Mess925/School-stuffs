/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:53:34 by hthant            #+#    #+#             */
/*   Updated: 2025/09/01 08:33:16 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << "-----------------------------------------1" << std::endl;
		// Bureaucrat a("a", 151);
		Bureaucrat b ("b", 149);
		b.decreaseGrade();
		b.getGrade();
		// std::cout << a <<std::endl;
	}
	catch (const std::exception &e){
		std::cout << "-----------------------------------------2" << std::endl;
		std::cout <<e.what() << std::endl;
	}
	try{
		std::cout << "-----------------------------------------3" << std::endl;
		Form a("a", 1 , 1);
		Bureaucrat b("b", 3);
		b.signForm(a);
	}
	catch (const std::exception &e){
		std::cout << "-----------------------------------------4" << std::endl;
		std::cout <<e.what() <<std::endl;
	}
	try{
		std::cout << "-----------------------------------------5" << std::endl;
		Form c("c", 150, 1);
		Bureaucrat b("b", 3);
		b.signForm(c);
		std::cout << c <<std::endl;
	}
	catch(const std::exception &e){
		std::cout << "-----------------------------------------6" << std::endl;
		std::cout << e.what() <<std::endl;
	}
	try{
		std::cout << "--------------test---------------" <<std::endl;
		Form a("a", 3, 3);
		Form b;
		std::cout << b << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() <<std::endl;
	}
}
