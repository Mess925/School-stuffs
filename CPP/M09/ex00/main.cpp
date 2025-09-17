/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:33:39 by hthant            #+#    #+#             */
/*   Updated: 2025/09/16 15:29:26 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"
# include <iostream>

int main(int ac, char** av){
	if(ac < 2){
		std::cout << "Error: need to pass the .txt file." << std::endl;
		return -1;
	}
	BitcoinExchange b;
	b.validFile(av[1]);
	b.loadData();
	return 0;
}
