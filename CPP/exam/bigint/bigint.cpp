/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:01:00 by hthant            #+#    #+#             */
/*   Updated: 2025/10/30 15:53:39 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bigint.hpp"
#include <ostream>

bigint::bigint() : _value("0"){}

bigint::bigint(const bigint& other): _value(other._value){}

bigint& bigint::operator=(const bigint& other){
	if(this != &other){
		_value = other._value;
	}
	return *this;
}

bigint::~bigint(){
	std::cout << "Destructed\n" << std::endl;
}

bigint::bigint(unsigned int number){
	_value = std::to_string(number);
}

bigint::bigint(std::string value){
	_value = value;
}

std::string bigint::getValue() const{
	return this->_value;
}

std::ostream& operator<<(std::ostream& os, const bigint& b){
	os << b.getValue();
	return os;
}

bigint bigint::operator+(const bigint& number) {
	std::string first = _value;
	std::string second = number._value;
	std::string result = "";

	int i = first.size() - 1;
	int j = second.size() - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry) {
        	int digit1 = i >= 0 ? first[i] - '0' : 0;
        	int digit2 = j >= 0 ? second[j] - '0' : 0;

        	int sum = digit1 + digit2 + carry;
        	carry = sum / 10;
        	result.insert(result.begin(), (sum % 10) + '0');
	
        	i--;
        	j--;
	}
	return bigint(result);
}

bigint& bigint::operator+=(const bigint& number){
	*this = *this + number;
	return *this;
}

bigint& bigint::operator++(){
	*this  = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int){
	bigint temp =  *this;
	*this = *this + bigint(1);
	return temp;
}
