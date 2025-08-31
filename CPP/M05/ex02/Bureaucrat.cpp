/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:57:30 by hthant            #+#    #+#             */
/*   Updated: 2025/08/31 20:00:37 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade){}


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
	std::cout<<"Bureaucrat "<<this->_name<<" is destroyed."<<std::endl;
}

void	Bureaucrat::increaseGrade(){
	if(this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::decreaseGrade(){
	if(this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

void	Bureaucrat::signForm(AForm& f) {
	try {
		f.beSigned(*this);
	} catch (const std::exception& e) {
		std::cout << this->_name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << this->_name << " signed " << f.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try{
		form.execute(*this);
		std::cout<< _name << " executed " << form.getName() <<std::endl;
	}
	catch (const std::exception& e){
		std::cout << _name << " couldn't execute " << form.getName() << " because" << e.what() <<std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat b)
{
	os << b.getName() << ", bureacurat grade "<< b.getGrade() <<std::endl;
	return (os);
}
