/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:37:32 by hthant            #+#    #+#             */
/*   Updated: 2025/09/17 19:45:30 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& other){
	*this = other;
}

RPN& RPN::operator=(const RPN& other){
	(void) other;
	return *this;
}

RPN::~RPN(){}

void	RPN::PolishEvaluator(const std::string& arg){
	std::stack<int> myStack;
	std::stringstream ss(arg);
	std::string arr;
	while(ss >> arr){
		if(arr == "+" || arr == "-" || arr == "*" || arr == "/")
		{
			std::cout << "The array can accept "<< arr<< std::endl;
		}
		else if{} 
			std::cout<< "The int is "<< arr << std::endl;
	}
}

