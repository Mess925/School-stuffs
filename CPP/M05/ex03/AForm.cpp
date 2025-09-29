/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:23:05 by hthant            #+#    #+#             */
/*   Updated: 2025/09/01 18:28:44 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm():
       	_name("Default Form"),
       	_isSigned(false),
       	_gradeToSign(0),
       	_gradeToExecute(0){}

AForm::AForm(const AForm& other):
       	_name(other._name),
       	_isSigned(other._isSigned),
       	_gradeToSign(other._gradeToSign),
       	_gradeToExecute(other._gradeToExecute){}

AForm& AForm::operator=(const AForm& other){
	if(this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm(){
	std::cout<<"AForm "<<this->_name<<" is destroyed."<<std::endl; 
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):
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

const char* AForm::GradeTooHighException::what() const throw(){
	return "AForm grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "AForm grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw(){
	return "Form is not signed!";
}

const	std::string AForm::getName() const {
	return this->_name;
}

bool	AForm::getIsSigned() const {
	return this->_isSigned;
}

int	AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int	AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat &b){
	if(b.getGrade() > _gradeToSign)
	       throw GradeTooLowException();
       _isSigned = true;
}

void	AForm::checkExecution(Bureaucrat const &executor) const {
	if(!_isSigned)
		throw FormNotSignedException();
	if(executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}	

std::ostream& operator<<(std::ostream &os, const AForm& f) {
	os << "AForm " << f.getName() << " \n\t isSigned: " << f.getIsSigned()
	<< " \n\t\t gradeToSign: " << f.getGradeToSign() << " \n\t\t gradeToExecute: "
	<< f.getGradeToExecute() << std::endl;
	return (os);
}

