/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:35:51 by hthant            #+#    #+#             */
/*   Updated: 2025/10/13 12:07:43 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bigint.hpp" 
#include <ostream>
#include <sstream>

bigint::bigint() : _value("0") {}

bigint::bigint(const bigint& other) : _value(other._value){
	*this = other;
}

bigint& bigint::operator=(const bigint& other){
	 _value = other._value;
	 return *this;
}

bigint::~bigint(){}

bigint::bigint(unsigned int n){
	_value = toStr(n);
}

std::string bigint::toStr(unsigned int n){
	std::ostringstream ss;
	ss << n;
	return ss.str();
}

std::string bigint:: getValue() const {
	return this->_value;
}

std::ostream& operator<<(std::ostream& os, const bigint& b){
	os << b.getValue();
	return (os);
}

bigint::bigint(std::string value){
	_value = value;
}

bigint bigint::operator+(const bigint& number){
	std::string a = _value;
	std::string b = number._value;
	std::string res = "";

	int i = a.size()-1;
	int j = b.size()-1;
	int o = 0;

	while(i >= 0 || j >= 0){
		int digitA, digitB;

		if( i >= 0 ){
			digitA = a[i] - '0';
			i--;
		}
		else 
			digitA = 0;
		if(j >= 0){
			digitB = b[j] - '0';
			j--;
		}
		else
			digitB = 0;
		int final = digitA + digitB + o;
		o = final/10;
		res = char(final % 10 + '0') + res;
	}
	return bigint(res);
}

bigint bigint::operator+=(const bigint& number){
	*this = *this + number;
	return  *this;
}


bigint bigint::operator++(){
	*this += bigint("1");
	return *this;
}

bigint bigint::operator++(int){
	bigint temp = *this;
	*this += bigint("1");
	return temp;
}

bigint bigint::operator<<(int n){
	if(_value == "0")	
		return *this;
	return (bigint( _value + std::string(n,'0')));
}

bigint bigint::operator>>(int n){
	if(_value.size() <= (size_t)n){
		return bigint("0");}
	return bigint(_value.substr(0, _value.size() - n));
};


bigint& bigint::operator<<=(int n){
	if(_value == "0")
		return *this;
	this->_value = (_value  + std::string(n , '0'));
	return *this;
}

bigint& bigint::operator>>+(int n){
	if(_value.size())
}
