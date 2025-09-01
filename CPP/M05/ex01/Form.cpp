/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:23:05 by hthant            #+#    #+#             */
/*   Updated: 2025/09/01 18:28:07 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form():
       	_name("no name:"),
       	_isSigned(false),
       	_gradeToSign(0),
       	_gradeToExecute(0){}

Form::Form(const Form& other):
       	_name(other._name),
       	_isSigned(other._isSigned),
       	_gradeToSign(other._gradeToSign),
       	_gradeToExecute(other._gradeToExecute){}

Form& Form::operator=(const Form& other){
	if(this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form(){
	std::cout<<"Form "<<this->_name<<" is destroyed."<<std::endl; 
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute):
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1){
		throw GradeTooHighException();
	}
	if(gradeToExecute > 150 || gradeToExecute > 150){
		throw GradeTooLowException();
	}
}

const	std::string Form::getName() const {
	return this->_name;
}

bool	Form::getIsSigned() const {
	return this->_isSigned;
}

int	Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int	Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void	Form::beSigned(const Bureaucrat &b){
	       if(b.getGrade() > _gradeToSign)
		       throw GradeTooLowException();
	       _isSigned = true;
}

std::ostream& operator<<(std::ostream &os, const Form& f) {
	os << "Form " << f.getName() << " \n\t isSigned: " << f.getIsSigned()
	<< " \n\t\t gradeToSign: " << f.getGradeToSign() << " \n\t\t gradeToExecute: "
	<< f.getGradeToExecute() << std::endl;
	return (os);
}
