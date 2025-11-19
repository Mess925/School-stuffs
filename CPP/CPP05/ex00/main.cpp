/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:57:41 by hthant            #+#    #+#             */
/*   Updated: 2025/08/29 23:40:46 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"

int main() {
	try{
		Bureaucrat a("a", 150);
		std::cout << a;
		a.decreaseGrade();
	}
	catch (const std::exception &e) {
		std::cout <<e.what() <<std::endl;
	}
	try{
		Bureaucrat b("b", 0);
		std::cout<<b;
		b.increaseGrade();
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
		Bureaucrat a("d", 150);
		a.increaseGrade();
		std::cout <<a;
		a.decreaseGrade();
		std::cout << a;
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
