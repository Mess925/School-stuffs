/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:57:41 by hthant            #+#    #+#             */
/*   Updated: 2025/08/29 09:35:12 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

int main() {
	try{
		Bureaucrat a("a", 150);
	}
	catch (const std::exception &e) {
		std::cout <<e.what() <<std::endl;
	}
    return 0;
}
