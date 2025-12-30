/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:24:31 by hthant            #+#    #+#             */
/*   Updated: 2025/11/26 11:34:50 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <climits>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

Merge::Merge() {}

Merge::Merge(const Merge& other) {
	*this = other;
}

Merge& Merge::operator=(const Merge& other) {
	if (this != &other) {
		_vectorData = other._vectorData;
		_dequeData  = other._dequeData;
	}
	return *this;
}

Merge::~Merge() {}

void Merge::checkInput(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		std::string arg = av[i];
		std::stringstream ss(arg);
		std::string token;

		while (ss >> token) {
			if (token.empty() || token[0] == '-' || token[0] == '+')
				throw std::invalid_argument("Invalid argument");

			for (size_t j = 0; j < token.size(); j++) {
				if (!std::isdigit(token[j]))
					throw std::invalid_argument("Invalid argument");
			}

			std::stringstream n(token);
			long num; n >> num;
			if (num < 0 || num > INT_MAX)
				throw std::out_of_range("Out of Int limit");

			_vectorData.push_back(static_cast<int>(num));
			_dequeData.push_back(static_cast<int>(num));
		}
	}
}

template <typename T>
void Merge::Display(const std::string& str, const T& data) {
	std::cout << str;

	int max_length = *std::max_element(data.begin(), data.end());
	std::stringstream ss;
	ss << max_length;
	int width = ss.str().length();

	if (data.size() <= 5) {
		for (size_t i = 0; i < data.size(); i++) {
			std::cout << std::setw(width) << data[i];
			if (i < data.size() - 1)
				std::cout << " ";
		}
	} else {
		for (size_t i = 0; i < 4; i++) {
			std::cout << std::setw(width) << data[i];
			if (i < 3)
				std::cout << " ";
		}
		std::cout << " [...]";
	}
	std::cout << std::endl;
}

template <typename T>
T generateJacobsthal(int n) {
	T a;
	if (n == 1) {
		a.push_back(0);
		a.push_back(1);
		return a;
	}
	a.push_back(0);
	a.push_back(1);

	while (a.back() < n) {
		a.push_back(a[a.size() - 1] + 2 * a[a.size() - 2]);
	}
	return a;
}

template <typename T, typename PairContainer>
T sort_small(
	const T& small,
	const T& big,
	const PairContainer& pairs
) {
	T orderedSmall;
	orderedSmall.clear();
	
	std::vector<bool> used(pairs.size(), false);

	for (size_t i = 0; i < big.size(); i++) {
		int B = big[i];
		
		for (size_t j = 0; j < pairs.size(); j++) {
			if (!used[j] && pairs[j].second == B) {
			if(B == 20){
			std::cout << "index is " << i << std::endl;
			std::cout << "BIG is " << B << std::endl;
			std::cout << "small is " << pairs[j].first << std::endl;
		}
				orderedSmall.push_back(pairs[j].first);
				used[j] = true;
				break;
			}
		}
	}

	if (orderedSmall.size() < small.size())
		orderedSmall.push_back(small.back());

	return orderedSmall;
}


std::vector<int> Merge::magic(std::vector<int>& data) {
	size_t size = data.size();
	if (size <= 1)
		return data;

	bool flag = false;
	int remain = 0;

	if (size % 2 != 0) {
		flag = true;
		remain = data[size - 1];
		size -= 1;
	}

	std::vector<std::pair<int, int> > result;
	for (size_t i = 0; i < size; i += 2) {
		int left = data[i];
		int right = data[i + 1];
		result.push_back(std::make_pair(left, right));
	}

	for (size_t i = 0; i < result.size(); i++) {
		if (result[i].first > result[i].second) {
			std::swap(result[i].first, result[i].second);
		}
	}

	std::vector<int> big;
	std::vector<int> small;

	for (size_t i = 0; i < result.size(); i++) {
		big.push_back(result[i].second);
		small.push_back(result[i].first);
	}

	big = magic(big);
	if (flag)
		small.push_back(remain);

	std::vector<int> sorted = big;
	small = sort_small(small, big, result);

	std::vector<int> jacob = generateJacobsthal<std::vector<int> >(small.size());

	size_t lastindex = 0;
	size_t jacobindex = 1;

	while (jacobindex < jacob.size() && (size_t)jacob[jacobindex] <= small.size()) {
		size_t endIndex = jacob[jacobindex];
		size_t firstIndex = jacob[jacobindex - 1];

		for (size_t i = endIndex; i > firstIndex; i--) {
			int value = small[i - 1];
			std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
			sorted.insert(it, value);
		}
		lastindex = endIndex;
		jacobindex++;
	}

	for (size_t i = lastindex; i < small.size(); i++) {
		int value = small[i];
		std::vector<int>::iterator it =
			std::lower_bound(sorted.begin(), sorted.end(), value);
		sorted.insert(it, value);
	}

	_vectorData = sorted;
	return _vectorData;
}

std::deque<int> Merge::magicD(std::deque<int>& data) {
	size_t size = data.size();
	if (size <= 1)
		return data;

	bool flag = false;
	int remain = 0;

	if (size % 2 != 0) {
		flag = true;
		remain = data[size - 1];
		size -= 1;
	}

	std::deque<std::pair<int, int> > result;
	for (size_t i = 0; i < size; i += 2) {
		int left = data[i];
		int right = data[i + 1];
		result.push_back(std::make_pair(left, right));
	}

	for (size_t i = 0; i < result.size(); i++) {
		if (result[i].first > result[i].second) {
			std::swap(result[i].first, result[i].second);
		}
	}

	std::deque<int> big;
	std::deque<int> small;

	for (size_t i = 0; i < result.size(); i++) {
		big.push_back(result[i].second);
		small.push_back(result[i].first);
	}

	big = magicD(big);
	if (flag)
		small.push_back(remain);

	std::deque<int> sorted = big;
	small = sort_small(small, big, result);

	std::deque<int> jacob = generateJacobsthal<std::deque<int> >(small.size());

	size_t lastindex = 0;
	size_t jacobindex = 1;

	while (jacobindex < jacob.size() && (size_t)jacob[jacobindex] <= small.size()) {
		size_t endIndex = jacob[jacobindex];
		size_t firstIndex = jacob[jacobindex - 1];

		for (size_t i = endIndex; i > firstIndex; i--) {
			int value = small[i - 1];
			std::deque<int>::iterator it =
				std::lower_bound(sorted.begin(), sorted.end(), value);
			sorted.insert(it, value);
		}
		lastindex = endIndex;
		jacobindex++;
	}

	for (size_t i = lastindex; i < small.size(); i++) {
		int value = small[i];
		std::deque<int>::iterator it =
			std::lower_bound(sorted.begin(), sorted.end(), value);
		sorted.insert(it, value);
	}

	_dequeData = sorted;
	return _dequeData;
}

void Merge::program(int ac, char** av) {

	if (ac < 2)
		throw std::out_of_range("Not enough Arguments");

	checkInput(ac, av);

	Display("Before: ", _vectorData);

	clock_t start = clock();
	magic(_vectorData);
	clock_t end = clock();

	clock_t startD = clock();
	magicD(_dequeData);
	clock_t endD = clock();

	Display("After : ", _vectorData);

	double timeTaken  = double(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	double timeTakenD = double(endD - startD) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vectorData.size()
	          << " elements with std::vector : " << timeTaken << " us\n";
	std::cout << "Time to process a range of " << _vectorData.size()
	          << " elements with std::deque  : " << timeTakenD << " us\n";

}
