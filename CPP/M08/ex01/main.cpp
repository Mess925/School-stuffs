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
# include <iostream>
# include <vector>

int main()
{
	try{
		Span sp = Span(90);
    		sp.addNumber(1);
    		sp.addNumber(3);
    		sp.addNumber(17);
    		sp.addNumber(9);
    		sp.addNumber(11);
    		std::vector<int> nums2;
    		for(int i = 1 ; i < 96; i++)
	    		nums2.push_back(i);
    		sp.addMulti(nums2.begin(), nums2.end());

    		std::cout << sp.shortestSpan() << std::endl;
    		std::cout << sp.longestSpan() << std::endl;
    		int min = *std::min_element( nums2.begin(), nums2.end());
    		std::cout << "Min is " << min << std::endl;
    		int max = *std::max_element(nums2.begin(), nums2.end());
    		std::cout << "Max is " << max << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "ERROR OUT OF LIMIT" << std::endl;
	}

    return 0;
}

