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
# include <algorithm>
#include <vector>

Span::Span() : _maxN(0) {}

Span::Span(unsigned int maxN): _nums() {
	this->_maxN = maxN;
}

Span::Span(int n){
	if(n < 0)
		throw std::exception();
	this->_maxN = n;
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


unsigned int Span::shortestSpan() {
	if (_nums.size() < 2)
		throw std::exception();

	int miniDiff = std::abs(_nums[1] - _nums[0]);
	for (size_t i = 1; i < _nums.size(); i++) {
		int diff = std::abs(_nums[i] - _nums[i - 1]);
		if (diff < miniDiff)
			miniDiff = diff;
	}
	return miniDiff;
}

unsigned int Span::longestSpan() {
	if (_nums.size() < 2)
		throw std::exception();

	int miniDiff = std::abs(_nums[1] - _nums[0]);
	for (size_t i = 1; i < _nums.size(); i++) {
		int diff = std::abs(_nums[i] - _nums[i - 1]);
		if (diff > miniDiff)
			miniDiff = diff;
	}
	return miniDiff;
}

std::vector<int>& Span::getarray(){
	return this->_nums;
}

void Span::addNumber(std::vector<int>& vec){
	_nums.insert(_nums.end(), vec.begin(), vec.end());
	if(_nums.size() > _maxN)
	{
		_nums.resize(_maxN);
		throw std::exception();
	}
}

