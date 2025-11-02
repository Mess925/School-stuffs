/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:12:12 by hthant            #+#    #+#             */
/*   Updated: 2025/10/30 15:52:01 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bigint.hpp" 

int main(){
	bigint c;
	bigint a(120);
	bigint b("33");
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "result is " << (a + b) << std::endl;
	std::cout << "a before a+b is " << a << std::endl;
	a+= b;
	std::cout << "a+=b is " << a <<std::endl;
	++a;
	std::cout << "a is " << a << std::endl;
	a++;
	std::cout << "a is " << a << std::endl;
	return 0;
}
