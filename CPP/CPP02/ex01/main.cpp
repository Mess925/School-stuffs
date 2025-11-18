/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:32:46 by hthant            #+#    #+#             */
/*   Updated: 2025/06/03 21:06:28 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

int main( void ) {
    Fixed a;
    std::cout << "--------------------" <<std::endl;
    Fixed const b( 10 );
    std::cout << "--------------------" <<std::endl;
    Fixed const c( 42.42f );
    std::cout << "--------------------" <<std::endl;
    Fixed const d( b );
    std::cout << "--------------------" <<std::endl;
    a = Fixed( 1234.4321f );
    std::cout << "--------------------" <<std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}
