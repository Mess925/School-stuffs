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

int RPN::calculation(int x, int y, char o){
	switch(o)
	{
		case '+':
			return (x + y);
		case '-':
			return (x - y);
		case '*':
			return (x * y);
		case '/':
			if( y != 0 )
				return ( x / y );
			else
				throw std::exception();
		default:
			throw std::exception();
	}
}


void	RPN::PolishEvaluator(const std::string& arg){
	std::stack<int> myStack;
	std::stringstream ss(arg);
	std::string arr;
	while(ss >> arr){
		if((arr == "+" || arr == "-" || arr == "*" || arr == "/") && arr.size() == 1){
			if(myStack.size() < 2)
				throw std::exception();
			int y = myStack.top();
			myStack.pop();
			int x = myStack.top();
			myStack.pop();
			myStack.push(calculation(x,y,arr[0]));
		}
		else {
			if(!isdigit(arr[0]) || arr.size()!= 1){
				std::cerr<<"This is not an integer " <<arr[0] <<std::endl;
				throw std::exception();

			}
			myStack.push(arr[0] - '0');
		}
	}
	if(myStack.size() != 1)
		throw std::exception();
	std::cout << myStack.top() <<std::endl;
}

