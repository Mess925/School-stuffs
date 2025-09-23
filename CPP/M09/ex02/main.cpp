/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:42:36 by hthant            #+#    #+#             */
/*   Updated: 2025/09/22 14:09:04 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"
#include <ctime>
# include <exception>
#include <iomanip>
# include <iostream>
# include <time.h>

int main(int ac, char **av)
{
	try{
		Merge a;
		clock_t start = clock();
		a.program(ac, av);
		clock_t end = clock();
		double time_taken = double( end - start )/CLOCKS_PER_SEC;
		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time taken is " << time_taken << std::endl;	
		return 0;
	}
	catch(const std::exception& e){
		std::cerr << "Error: "<< e.what() <<std::endl;
	}
	return 1;
}
