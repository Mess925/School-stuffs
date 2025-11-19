/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:38:40 by hthant            #+#    #+#             */
/*   Updated: 2025/09/09 13:00:39 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
# include <iostream>
# include <vector>
# include <algorithm>

int main()
{
	srand(time(NULL));
	try{
		//random test
		std::cout << "== RANDOM TEST CASE ==\n" << std::endl;
		Span sp = Span(90);
    		sp.addNumber(1);
    		sp.addNumber(3);
    		sp.addNumber(17);
    		sp.addNumber(19);
    		sp.addNumber(18);
    		std::vector<int> nums2;
    		for(int i = 1 ; i < 96; i++)
	    		nums2.push_back(i);

    		std::cout << sp.shortestSpan() << std::endl;
    		std::cout << sp.longestSpan() << std::endl;
    		int min = *std::min_element( nums2.begin(), nums2.end());
    		std::cout << "Min of nums is " << min << std::endl;
    		int max = *std::max_element(nums2.begin(), nums2.end());
    		std::cout << "Max of nums is " << max << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "ERROR OUT OF LIMIT" << std::endl;
	}
	try{
		//subject test case
		std::cout << "\n== Subject Test Case == \n" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "ERROR OUT OF LIMIT" << std::endl;
	}
	try{
		//90 - 1 max is 89 and min is 1
		std::cout << "\n== Max has to be 89 (90 -1 ) and min  has to be 89 too ==\n\n";
		Span sp = Span(100);
		sp.addNumber(1);
		sp.addNumber(90);
		std::vector<int>sp2;
		for(int i = 10; i < 80 ; i++)
			sp2.push_back(i);	
    		std::cout << "Shortest span is "<< sp.shortestSpan() << std::endl;
    		std::cout << "Longest span is " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "ERROR OUT OF LIMIT" << std::endl;
	}
	try{
		//throw error because only one number
		std::cout << "\n\n== Need to throw error ==\n\n";
		Span sp = Span(100);
		sp.addNumber(1);
    		std::cout << "Shortest span is "<< sp.shortestSpan() << std::endl;
    		std::cout << "Longest span is " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "ERROR OUT OF LIMIT" << std::endl;
	}
	try{
		// throw error becuase of minus value (-)
		std::cout << "\n\n== Need to throw error unsigned n with minus value ==\n\n";
		Span sp = Span(-2);
		sp.addNumber(-1);
		sp.addNumber(1);
    		std::cout << "Shortest span is "<< sp.shortestSpan() << std::endl;
    		std::cout << "Longest span is " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "ERROR OUT OF LIMIT" << std::endl;
	}
	try{
		// throw error more than maxN
		std::cout << "\n\n== I wanna kill myself right now ==\n\n";
		Span sp = Span(5);
		sp.addNumber(-1);
		sp.addNumber(1);
		sp.addNumber(-1);
		sp.addNumber(-1);
		sp.addNumber(1);
		sp.addNumber(1);
    		std::cout << "Shortest span is "<< sp.shortestSpan() << std::endl;
    		std::cout << "Longest span is " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "ERROR OUT OF LIMIT" << std::endl;
	}
	try{
		// throw error more than maxN
		std::cout << "\n\n== HELL YEH ==\n\n";
		Span sp = Span(1000000);
		sp.addNumber(1);
		sp.addNumber(-1);
		std::vector<int> vec;
		for(int i = 0; i < 100000; i++){
			int j = rand();
			vec.push_back(j);
		}
		sp.addNumber(vec);
		std::cout << sp.getarray().size() << std::endl;
    		std::cout << "Shortest span is "<< sp.shortestSpan() << std::endl;
    		std::cout << "Longest span is " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "ERROR OUT OF LIMIT" << std::endl;
	}

    return 0;
}
