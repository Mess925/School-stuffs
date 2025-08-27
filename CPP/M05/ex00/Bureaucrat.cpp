/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:44:04 by hthant            #+#    #+#             */
/*   Updated: 2025/08/28 01:02:44 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {}

int	Bureacurat::getGrade() const {
	return this->_grade;
}

std::string& Bureacurat::getName() const {
	return this->_name;
}

Bureaucrat::Bureaucrat(std::string _name, int _graddd)

Bureacurat::Bureacurat(const Bureacurat& other) 
{
	if(this != &other)
		this->_grade = other._grade;
}

Bureacurat& Bureacurat::operator=(const Bureacurat& other){
	if(this != other)
		this->_grade = other._grade;
	return (*this);
}

Bureacurat::Bureacurat(std::string _name, int _grade) : _name(name)
{
	if()
}

Bureacurat::~Bureacurat(){
	std::cout<<"Bureacurat "<<this->getName()<<" is destroyed."<<std::endl;
}

