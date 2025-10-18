/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:57:24 by hthant            #+#    #+#             */
/*   Updated: 2025/10/13 12:05:44 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bigint.hpp"

int main(){
	bigint a(42);
	// bigint b(3);
	bigint b("4");
	std::cout << "a + b is "<< a + b<< std::endl;
	a += b;
	std::cout << "a is " << a << std::endl;
	std::cout << "a is " << ++a << std::endl;
	std::cout << "a is " << a++ << std::endl;
	std::cout << "a is " << a <<std::endl;
	std::cout << "a is " << (a << 4) << std::endl;
	std::cout << "a is " << ( a >> 2 ) <<std::endl;
	std::cout << "a is " << (a <<= 4) << std::endl;
	std::cout << " a is " << a << std::endl;
	return 0;
}
