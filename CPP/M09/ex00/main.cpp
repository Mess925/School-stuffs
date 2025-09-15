/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:33:39 by hthant            #+#    #+#             */
/*   Updated: 2025/09/12 14:38:37 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int main(int ac, char** av){
	if(ac < 2)
		return 1;
	BitcoinExchange b;
	b.isValidFile(av[1]);
	return 0;
}
