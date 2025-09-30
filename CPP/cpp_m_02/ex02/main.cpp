/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:32:46 by hthant            #+#    #+#             */
/*   Updated: 2025/06/16 15:17:07 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
#include <stdexcept>

int main( void ) {
{   
    	Fixed a;
    	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    	std::cout << a << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << ++a << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << a << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << a++ << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << a << std::endl;
    	std::cout << "------------------" << std::endl;
	std::cout << b << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << a/b << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << Fixed::max( a, b ) << std::endl << std::endl;
}
{
    	Fixed a(2.5f);
    	Fixed b(5.0f);
    	std::cout << (a > b) << std::endl; // should print 0 (false)
    	std::cout << "------------------" << std::endl;
    	std::cout << (b > a) << std::endl; // should print 1 (true)
}
{
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "New test case" << std::endl;
	try{
	Fixed a(3);
	Fixed b(0);
	std::cout << a/b << std::endl;
	}
	catch(const std::runtime_error& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------" << std::endl;
}
{   
    	Fixed a;
    	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    	std::cout << a << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << --a << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << a << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << a-- << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << a << std::endl;
    	std::cout << "------------------" << std::endl;
	std::cout << b << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << a/b << std::endl;
    	std::cout << "------------------" << std::endl;
    	std::cout << Fixed::max( a, b ) << std::endl << std::endl;
}
    return 0;
}
