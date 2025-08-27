/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:44:04 by hthant            #+#    #+#             */
/*   Updated: 2025/08/27 21:13:33 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Default"), _grade(150)
{
	std::cout<<"Default bureaucrat " << _name <<" is created with grade "<< _grade <<" is created."<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade)
{
	std::cout<<"Copy Bureaucrat "<< _name <<" is created with grade "<< _grade<<" is created."<< std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this!= other)
	{
		_name = other._name;
		_grade = other._grade;
	}
	std::cout<<"Bureaucrat" << _name<<"is assigned with grade"<<_grade<"is assigned."<<std::endl;
	return *this;
}

Bureaucrat::~Buraucrat()
{
	std::cout<<"Bureaucrat"<<_name<<"is destroyed."<<std::endl;
}
