/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:57:30 by hthant            #+#    #+#             */
/*   Updated: 2025/08/29 12:16:05 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name) 
{
	if(this != &other){
		this->_grade = other._grade;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if(this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if(grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if(grade>150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat(){
}

void	Bureaucrat::increaseGrade(){
	if(this->_grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::decreaseGrade(){
	if(this->_grade >= 150) 
		throw (Bureaucrat::GradeTooLowException()); 
	else
		this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too High!";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too Low!";
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat b)
{
	os << b.getName() << ", bureacurat grade "<< b.getGrade() <<std::endl;
	return (os);
}
