/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:24:31 by hthant            #+#    #+#             */
/*   Updated: 2025/09/22 15:35:15 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"
# include <algorithm>
# include <cstddef>
# include <iomanip>
# include <iostream>
# include <climits>
#include <iterator>
# include <stdexcept>
# include <sstream>
# include <string>
# include <utility>
# include <vector>

Merge::Merge(){}

Merge:: Merge(const Merge& other){
	*this = other;
}

Merge& Merge::operator=(const Merge& other){
	if(this != &other){
		_vecetorData = other._vecetorData;
		_dequeData = other._dequeData;
	}
	return *this;
}

Merge::~Merge(){};

bool Merge::checkInput(int ac, char **av){
	for(int i = 1; i < ac; i++){
		std::string arg = av[i];
		std::stringstream ss(arg);
		std::string token;

		while(ss >> token){
			if(token.empty() || (token[0] == '-' && token.size()> 2) || token[0] == '+'){
				throw :: std::invalid_argument("Invalid argument");
				return false;
			}
			for(size_t j = 0; j < token.size(); j++){
				if(!std::isdigit(token[j])){
					throw ::std::invalid_argument("Invalid argument");
					return false;
					}
			}
			std::stringstream n(token);
			long num;
			n >> num;
			if(num < 0 || num > INT_MAX){
				throw:: std::out_of_range("Out of Int limit");
				return false;
			}
			_vecetorData.push_back(static_cast<int>(num));
			_dequeData.push_back(static_cast<int>(num));
		}
	} 
	return true;
}

void Merge::Display(const std::string& str, const std::vector<int>& data){
	std::cout << str;
	int max_lenth = *std::max_element(data.begin(), data.end());
	std::stringstream ss;
    	ss << max_lenth;
    	int width = ss.str().length();
	if(data.size() <= 5) {
		for(size_t i = 0;i < data.size(); i++){
			std::cout <<  std::setw(width) << data[i];
			if(i < data.size() -1 )
				std::cout << " " ;
		}
	}
	else {
		for(size_t j = 0; j < 4; j++){
			std::cout << std::setw(width) << data[j];
			if(j < 3)
				std::cout << " ";
		}
		std::cout << " [...]";
	}
	std::cout << std::endl;
}

std::vector<int> generateJacobsthal(int n){
	std::vector<int> a;
	if (n == 1){
		a.push_back(0);
		a.push_back(1);
		return  a;
	}	   
	a.push_back(0);
	a.push_back(1);
	while (a.back() < n) {
		a.push_back(a[a.size()-1] + 2* a[a.size() - 2]);
	}
	return a;
}

std::vector<int>mergeLeftRight(std::vector<int> left, std::vector<int> right){
	std::vector<int> result;
	size_t i = 0;
	size_t j = 0;

	while(i < left.size() & j < right.size()){
		if(left[i] < right[j]){
			result.push_back(left[i]);
			i++;}
		else{
			result.push_back(right[j]);
			j++;}
	}
	while(i < left.size()){
		result.push_back(left[i]);
		i++;}
	while(j < right.size()){
		result.push_back(right[j]);
		j++;}
	return  result;
}

void merge(std::vector<int>& big){
	if(big.size() <= 1)
		return;
	size_t size = big.size()/2;
	std::vector<int> left(big.begin(), big.begin() + size);
	std::vector<int> right(big.begin() + size, big.end());
	merge(left);
	merge(right);
	big = mergeLeftRight(left,right);
}
int findPairedElement(std::vector<std::pair<int, int> >& pair, int big){
	for(size_t i = 0; i < pair.size(); i++){
		if(pair[i].second == big)
			return pair[i].first;
	}
	return -1;
}

void Merge::magic(const std::vector<int>& data)
{
	size_t size=data.size();
	if(size <= 1)
		return;
	int remain;
	bool flag = 0;
	if(size %2 != 0)
	{
		flag = 1;
		remain = data[size - 1];
		size -= 1;
	}
	std::vector<std::pair<int,int> >result;
	for(size_t i = 0;i < size; i += 2){
		int left = data.at(i);
		int right = data.at(i+1);
		result.push_back(std::make_pair(left, right));
	}
	for(size_t i =0; i < result.size(); i++){
		if(result[i].first > result[i].second)
			std::swap(result[i].first,result[i].second);
	}
	std::vector<int>big;
	std::vector<int>small;
	for(size_t i  = 0; i < result.size(); i++){
			big.push_back(result[i].second);
			small.push_back(result[i].first);
	}
	merge(big);
	if(flag)
		small.push_back(remain);

	std::vector<int> sorted = big;
	int firstToInsert =  findPairedElement(result,sorted[0]);
	if(firstToInsert != -1){
		std::vector<int>::iterator it = std::find(small.begin(), small.end(), firstToInsert);
		if(it != small.end()){
			sorted.insert(sorted.begin(), *it);
			small.erase(it);
		}
	}
	for(size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << ";";
	std::cout << std::endl;
	std::vector<int> jacob = generateJacobsthal(small.size());
	size_t lastindex = 0;
	size_t jacobindex = 1;
	while(jacobindex < jacob.size() && (size_t)jacob[jacobindex] <= small.size()){
		size_t endIndex = jacob[jacobindex];
		size_t firstIndex = jacob[jacobindex - 1];
		for(size_t i = endIndex; i > firstIndex ; i--){
			int value = small[i - 1];
			std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
			sorted.insert(it, value);
		}
		lastindex = endIndex;
		jacobindex++;
		for(size_t i =0; i < sorted.size(); i++)
			std::cout << "h" <<sorted[i] << ";";
		std::cout << std::endl;
	}
	for(size_t i = 0; i < small.size(); i++)
		std::cout << small[i] << ";";
	std::cout << std::endl;
	for(size_t i =0; i < sorted.size(); i++)
		std::cout << "h" <<sorted[i] << ";";
	std::cout << std::endl;
	for(size_t i = lastindex; i < small.size(); i++){
		int value = small[i];
		std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
		sorted.insert(it, value);
	}
	for(size_t i =0; i < sorted.size(); i++)
		std::cout << "h" <<sorted[i] << ";";
	std::cout << std::endl;

       _vecetorData = sorted;
}

bool Merge::program(int ac, char** av){
	if(ac < 2){
		std::cerr << "Not enough Arguments" << std::endl;
		return false;
	}
	if(!checkInput(ac,av)){
		throw:: std::invalid_argument("Invalid Argument");
		return false;
	}

	Display("Before: ", _vecetorData);
	magic(_vecetorData);
	Display("After : ", _vecetorData);

	return true;
}

 
