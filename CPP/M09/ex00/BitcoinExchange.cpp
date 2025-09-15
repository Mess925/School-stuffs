/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:15:17 by hthant            #+#    #+#             */
/*   Updated: 2025/09/12 14:45:35 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	this->_money = other._money;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	if(this != &other)
		this->_money = other._money;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){};

bool BitcoinExchange::isValidFile(const std::string &fileName){
	std::ifstream file;
	file.open(fileName.c_str());
	if(!file.is_open())
		std::cout << "Cannot open the .txt file" << std::endl;
	else
		std::cout << "IT is valid" << std::endl;
	return true;
}
