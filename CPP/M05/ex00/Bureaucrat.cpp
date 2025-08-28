/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:57:30 by hthant            #+#    #+#             */
/*   Updated: 2025/08/28 09:57:54 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {}

int	Bureacurat::getGrade() const {
	return this->_grade;
}

std::string& Bureacurat::getName() const {
	return this->_name;
}

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

Bureacurat::Bureacurat(std::string name, int _grade) : _name(name)
{
	if()
}

Bureacurat::~Bureacurat(){
	std::cout<<"Bureacurat "<<this->getName()<<" is destroyed."<<std::endl;
}

