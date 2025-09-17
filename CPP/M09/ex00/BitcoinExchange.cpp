/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:43:35 by hthant            #+#    #+#             */
/*   Updated: 2025/09/17 17:17:43 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"
# include <iostream>
# include <fstream>
# include <sstream>
#include <string>

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

bool BitcoinExchange::validValue(const std::string& valueStr, bool check) {
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
    if (value > 1000 && check) {
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

bool 	BitcoinExchange::validLine(const std::string& line, Data& d, bool check){
	d.deli_pos = line.find(d.deli);
	if(d.deli_pos == std::string::npos){
		std::cerr<< "Error: bad input wiht no " << d.deli <<" => "<< line.substr(0,d.deli_pos) << std::endl;
		return false;
	}
	d.date= line.substr(0,d.deli_pos);
	d.value= line.substr(d.deli_pos + 1);
	if(d.date.size() != 10)
		d.date = line.substr(0, d.deli_pos -1);
	if(!validDate(d.date) || !validValue(d.value, check))
		return false;	
	return true;
}
/*
bool BitcoinExchange::validFile(const std::string &fileName){
	std::ifstream file(fileName.c_str());
	if(!file.is_open())
	{
		std::cout << "Cannot open the .txt file" << std::endl;
		return false;
	}
	Data d;
	d.deli = '|';
	std::string line;
	std::getline (file, line);
	if (line != "date | value") return false;
	while(std::getline(file,line)){
		if(line == "date | value")
			continue;
		else
			validLine(line , d, true);
	}
	file.close();
	return true;
}
*/


void BitcoinExchange::processInputFile(const std::string& fileName) {
    std::ifstream file(fileName.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file => " << fileName << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    Data d;
    d.deli = '|';
    loadData(); 

    while (std::getline(file, line)) {
        if (!validLine(line, d, true)) {
            continue;
        }

        std::map<std::string, double>::iterator it = _money.lower_bound(d.date);
        double rate = 0.0;
        
        if (it != _money.end() && it->first == d.date) {
            rate = it->second;
        } else {
            if (it != _money.begin()) {
                --it;
                rate = it->second;
            } else {
                std::cerr << "Error: Date " << d.date << " is before the earliest record." << std::endl;
                continue;
            }
        }

        double value;
        std::stringstream ss(d.value);
        if (ss >> value) {
            std::cout << d.date << " => " << value << " = " << value * rate << std::endl;
        } else {
            std::cerr << "Error: Invalid value format => " << d.value << std::endl;
        }
    }
    file.close();
}


bool BitcoinExchange::loadData(){
	std::ifstream file("data.csv");
	if(!file.is_open())
	{
		std::cerr<<"ERROR"<< std::endl;
		return false;
	}
	std::string line;
	std::getline(file, line);
	Data d;
	d.deli = ',';
	while(std::getline(file,line))
	{
		validLine(line,d, false);
		std::stringstream ss(d.value);
		double rate;
		if(ss >> rate)
			_money[d.date] = rate;
	}
	file.close();
	return true;
}




















