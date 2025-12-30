/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:37:32 by hthant            #+#    #+#             */
/*   Updated: 2025/09/22 11:29:51 by hthant           ###   ########.fr       */
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
/*
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
				throw std::logic_error( std::string ("division by zero"));
		default:
			throw std::invalid_argument( std::string ("Invalid argument"));
	}
}
*/
int RPN::calculation(int x, int y, char op) {
    long long result;
    switch (op) {
        case '+':
            if (((y > 0) && (x > INT_MAX - y)) || ((y < 0) && (x < INT_MIN - y))) {
                throw std::overflow_error("Integer overflow detected during addition.");
            }
            result = (long long)x + y;
            break;
        case '-':
             if (((y > 0) && (x < INT_MIN + y)) || ((y < 0) && (x > INT_MAX + y))) {
                throw std::overflow_error("Integer overflow detected during subtraction.");
            }
            result = (long long)x - y;
            break;
        case '*':
            if (x != 0 && (y > INT_MAX / abs(x) || y < INT_MIN / abs(x))) {
                throw std::overflow_error("Integer overflow detected during multiplication.");
            }
	    result = (long long)x * y;
	    break;
        case '/':
            if (y == 0) {
                throw std::runtime_error("Division by zero.");
            }
            if (x == INT_MIN && y == -1) {
                throw std::overflow_error("Integer overflow detected (INT_MIN / -1).");
            }
            result = (long long)x / y;
            break;
        default:
            throw std::invalid_argument("Unknown operator.");
    	}
    	return static_cast<int>(result);
}

void	RPN::PolishEvaluator(const std::string& arg){
	std::stack<int> myStack;
	std::stringstream ss(arg);
	std::string arr;
	while(ss >> arr){
		if((arr == "+" || arr == "-" || arr == "*" || arr == "/") && arr.size() == 1){
			if(myStack.size() < 2)
				throw std::length_error(std::string ("Invalid out of range"));
			int y = myStack.top();
			myStack.pop();
			int x = myStack.top();
			myStack.pop();
			myStack.push(calculation(x,y,arr[0]));
		}
		else {
			if(!isdigit(arr[0]) || arr.size()!= 1)
				throw std::invalid_argument( std::string ("Invalid argument"));
			myStack.push(arr[0] - '0');
		}
	}
	if(myStack.size() != 1)
		throw std::length_error(std::string ("Invalid out of range"));
	std::cout << myStack.top() <<std::endl;
}

