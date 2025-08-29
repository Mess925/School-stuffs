/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:53:34 by hthant            #+#    #+#             */
/*   Updated: 2025/08/29 23:47:30 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

int main() {
	try {
		Bureaucrat a("a", 150);
	}
	catch (const std::exception &e){
		std::cout <<e.what() << std::endl;
	}
	try{
		Form a("a", false, 1 , 1);
		Bureaucrat b("b", 3);
		b.signForm(a);
	}
	catch (const std::exception &e){
		std::cout <<e.what() <<std::endl;
	}
	try{
		Form c("c", false, 150, 1);
		Bureaucrat b("b", 3);
		b.signForm(c);
	}
	catch(const std::exception &e){
		std::cout << e.what() <<std::endl;
	}
}
