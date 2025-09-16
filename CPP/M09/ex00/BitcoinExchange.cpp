/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:43:35 by hthant            #+#    #+#             */
/*   Updated: 2025/09/16 15:51:35 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"
# include <iostream>
# include <fstream>
# include <sstream>

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

static void writeErrorMsg(const std::string& msg,const std::string& val){
	std::cout << "Error: ";
	std::cerr<< msg << " => "<< val<< std::endl;
}

bool BitcoinExchange::validValue(const std::string& valueStr) {
    if (valueStr.empty()) {
	    writeErrorMsg(std::string("empty value"),valueStr);
	    return false;
    }
    std::stringstream ss(valueStr);
    double value;
    if (!(ss >> value)) {
	    writeErrorMsg(std::string("not a number"),valueStr);
	    return false;
    }
    std::string remaining;
    if (ss >> remaining) {
	    writeErrorMsg(std::string("not a number"),valueStr);
	    return false;
    }
    if (value < 0) {
	    writeErrorMsg(std::string("not a positive number"),valueStr);
	    return false;
    }
    if (value > 1000) {
	    writeErrorMsg(std::string("too large a number"),valueStr);
	    return false;
    } 
    return true;
}

bool BitcoinExchange::validDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        writeErrorMsg(std::string("bad date format"), date);
        return false;
    }
    
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (date[i] < '0' || date[i] > '9') {
            writeErrorMsg(std::string("date with nonnumerical"), date);
            return false;
        }
    }

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    int year, month, day;
    std::stringstream ssYear(yearStr);
    std::stringstream ssMonth(monthStr);
    std::stringstream ssDay(dayStr);
    ssYear >> year;
    ssMonth >> month;
    ssDay >> day;

    if (month < 1 || month > 12) {
        writeErrorMsg(std::string("invalid month"), date);
        return false;
    }
    
    if (day < 1 || day > 31) {
        writeErrorMsg(std::string("invalid day"), date);
        return false;
    }

    std::string months[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    if (month == 2) {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        int maxDays = isLeap ? 29 : 28;
        if (day > maxDays) {
            writeErrorMsg(std::string("invalid day for February"), date);
            return false;
        }
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        std::string specificErrorMsg = "invalid day for " + months[month];
        writeErrorMsg(specificErrorMsg, date);
        return false;
    }
    
    return true;
}

bool	BitcoinExchange::validLine(const std::string& line){
	InputData inputRecord;
	inputRecord.deli_pos = line.find('|');
	if(inputRecord.deli_pos == std::string::npos){
		std::cerr<< "Error: bad input => "<< line.substr(0, inputRecord.deli_pos) << std::endl;
		return false;
	}
	inputRecord.date = line.substr(0,inputRecord.deli_pos - 1);
	inputRecord.value = line.substr(inputRecord.deli_pos + 2);
	if(!validDate(inputRecord.date) || !validValue(inputRecord.value))
		return false;
	return true;
}

bool BitcoinExchange::isValidFile(const std::string &fileName){
	std::ifstream file(fileName.c_str());
	if(!file.is_open())
		std::cout << "Cannot open the .txt file" << std::endl;
	std::string line;
	while(std::getline(file,line)){
		if(line == "date | value")
			continue;
		else
			validLine(line);
	}
	file.close();
	return true;
}
