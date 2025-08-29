/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:57:41 by hthant            #+#    #+#             */
/*   Updated: 2025/08/29 12:16:16 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

int main() {
	try{
		Bureaucrat a("a", 150);
	}
	catch (const std::exception &e) {
		std::cout <<e.what() <<std::endl;
	}
	try{
		Bureaucrat b("b", 0);
	} 
	catch (const std::exception &e){
		std::cout <<e.what() <<std::endl;
	}
	try{
		Bureaucrat c("c", 151);
	}
	catch (const std::exception &e)
	{
		std::cout <<e.what() <<std::endl;    
	}
	try{
		Bureaucrat a("a", 150);
		a.getGrade();
		a.increaseGrade();
		a.getGrade();
		a.decreaseGrade();
		a.getGrade();
		a.getName();
	}
	catch(const std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	try{
		Bureaucrat test("test",40);
		std::cout<<test<<std::endl;
	}
	catch(const std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
    return 0;
}
