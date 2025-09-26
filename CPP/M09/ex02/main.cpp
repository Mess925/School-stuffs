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
# include <exception>
# include <iostream>

int main(int ac, char **av)
{
	try{
		Merge a;
		a.program(ac, av);
		return 0;
	}
	catch(const std::exception& e){
		std::cerr << "Error: "<< e.what() <<std::endl;
	}
	return 1;
}
