/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:36:54 by hthant            #+#    #+#             */
/*   Updated: 2025/09/09 13:18:35 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span() : _maxN(0) , _nums() {}

Span::Span(unsigned int maxN): _nums() {
	this->_maxN = maxN;
}

Span::Span(const Span& other){
	this->_maxN = other._maxN;
	this->_nums = other._nums;
}

Span& Span::operator=(const Span& other){
	if(this != &other)
	{
		this->_maxN = other._maxN;
		this->_nums = other._nums;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int n){
	if(_nums.size() >= _maxN){
		throw std::exception();
	}
	_nums.push_back(n);
}

unsigned int Span::shortestSpan(){
	if(_nums.size() < 2){
		throw std::exception();
	}
	std::sort(_nums.begin(), _nums.end());
	int minDiff = (int)longestSpan();
	for(int i = 0; i < (int)_nums.size(); i++){
		if(_nums[i] - _nums[i-1] < minDiff){
			minDiff = _nums[i] - _nums[i -1];
		}
	}
	return minDiff;
}

unsigned int Span::longestSpan() {
	if(_nums.size() < 2){
		throw std::exception();
	}
	int maxInt = *std::max_element(_nums.begin(), _nums.end());
	int minInt = *std::min_element(_nums.begin(), _nums.end());

	return static_cast<unsigned int>(maxInt - minInt);
				
} 

