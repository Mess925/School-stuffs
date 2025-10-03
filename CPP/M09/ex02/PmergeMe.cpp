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
# include <ctime>
# include <iomanip>
# include <iostream>
# include <climits>
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
		_vectorData = other._vectorData; _dequeData = other._dequeData; }
	return *this;
}

Merge::~Merge(){}; void Merge::checkInput(int ac, char **av){ for(int i = 1; i < ac; i++){
		std::string arg = av[i];
		std::stringstream ss(arg);
		std::string token;

		while(ss >> token){
			if(token.empty() || (token[0] == '-' && token.size()> 2) || token[0] == '+')
				throw :: std::invalid_argument("Invalid argument");
			for(size_t j = 0; j < token.size(); j++){
				if(!std::isdigit(token[j]))
					throw ::std::invalid_argument("Invalid argument");
			}
			std::stringstream n(token);
			long num;
			n >> num;
			if(num < 0 || num > INT_MAX)
				throw:: std::out_of_range("Out of Int limit");
			_vectorData.push_back(static_cast<int>(num));
			_dequeData.push_back(static_cast<int>(num));
		}
	} 
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
int n = 0;
int findPairedElement(std::vector<std::pair<int, int> >& pair, int big){
	for(size_t i = 0; i < pair.size(); i++){
		if(pair[i].second == big){
			n++;
			return pair[i].first;
			
		}
	}
	return -1;
}

std::vector<int> Merge::magic(std::vector<int>& data)
{
	size_t size=data.size();
	if(size <= 1)
		return data;
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
		if(result[i].first > result[i].second){
			std::swap(result[i].first,result[i].second);
			n++;
		}
	}
	std::vector<int>big;
	std::vector<int>small;
	for(size_t i  = 0; i < result.size(); i++){
			big.push_back(result[i].second);
			small.push_back(result[i].first);
	}
	big = magic(big);
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
			n++;
		}
		lastindex = endIndex;
		jacobindex++;
	}
	for(size_t i = lastindex; i < small.size(); i++){
		int value = small[i];
		std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
		sorted.insert(it, value);
		n++;
	}
       _vectorData = sorted;
       return _vectorData;
}

void Merge::program(int ac, char** av){

	if(ac < 2)
		throw::std::out_of_range("Not enough Arguments");
	checkInput(ac,av);

	Display("Before: ", _vectorData);
	clock_t start = clock();
	magic(_vectorData);
	clock_t end = clock();
	// clock_t startD = clock();
	// magicD(_dequeData);
	// clock_t endD = clock();
	Display("After : ", _vectorData);
	double timeTaken = double(end - start)/CLOCKS_PER_SEC;
	// double timeTakenD = double(endD - startD)/CLOCKS_PER_SEC; 
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vectorData.size() << " elements with std::vector : " << timeTaken << " us" << std::endl;
	// std::cout << "Time to process a range of " << _vectorData.size() << " elements with std::deque : " << timeTakenD << " us" << std::endl;
	std::cout << "TOTAL n " << n <<std::endl;
}

 
