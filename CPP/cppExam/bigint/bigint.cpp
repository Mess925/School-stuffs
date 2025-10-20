/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:59:53 by hthant            #+#    #+#             */
/*   Updated: 2025/10/19 18:11:23 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bigint.hpp"
#include <filesystem>
#include <string>
# include <vector>

bigint::bigint(): _value(0){}

bigint::bigint(const bigint& other): _value(other._value){}

bigint& bigint::operator=(const bigint& other){
	if(this != &other)
		_value = other._value;
	return *this;
}

bigint::~bigint(){}

bigint::bigint(unsigned int n){
	std::string value = std::to_string(n);
	this->_value = value;
}

bigint::bigint(std::string value){
	this->_value = value;
}

std::string bigint::getValue() const {
	return this->_value;
}

std::ostream& operator<<(std::ostream& os, const bigint b){
	os << b.getValue();
	return os;
}

bigint bigint::operator+(const bigint& b){
	std::string a = this->_value;
	std::string d = b._value;
	std::string c = "";

	int i = a.length() - 1;
	int j = d.length() - 1;
	int sum = 0;
	while( i >= 0 || j >= 0 || sum){
		int digitA, digitB;

		if(i >= 0){
			digitA = a[i] - '0';
			i--;
		}
		else {
			digitA = 0;
		}
		if(j >= 0){
			digitB = d[j] - '0';
			j--;
		}
		else {
			digitB = 0;
		}
		sum =  digitA + digitB + sum;
		c = char (sum % 10 +'0') + c; 
		sum = sum/10;
	}	
	return bigint(c);
}

bigint bigint::operator*(const bigint& n){
	std::string a = this->_value;
	std::string b = n._value;

	std::string total;
	std::vector<int> arr(a.size()+ b.size(), 0);
	for(int i = a.size() -1; i >= 0 ; i--){
		for(int j = b.size() -1; j >=0; j--){
			int res = ((a[i] - '0') * (b[j] - '0')); 
			total= std::to_string(res);
		}
	}
	return bigint(total);

}
